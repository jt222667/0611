function [M, C, G, tau, DynInfo] = DynamicsGenerator(LP, SV, DynParam, gravity)
% DynamicsGenerator  自动生成可重构机器人树形拓扑动力学模型。
%
%   [M, C, G] = DynamicsGenerator(LP, SV, DynParam)
%   [M, C, G, tau, DynInfo] = DynamicsGenerator(..., gravity)
%
% 输入：
%   LP / SV   : 由 LP_generate、SV_generate 生成的构型与状态结构体。
%   DynParam  : 动力学参数结构体数组，可按配置中的模块实例编号填写：
%               DynParam(i).mass    = m_i;
%               DynParam(i).com     = [x_i, y_i, z_i];
%               DynParam(i).inertia = [Ixx Iyy Izz Ixy Iyz Ixz];
%               未填写、[] 或 NaN 的参数会被视为未知，并在本函数中按 0 参与计算，
%               同时在 DynInfo.missing 中记录，便于后续补充。
%   gravity   : 可选，惯性系重力加速度向量，默认 [0; 0; -9.81] (m/s^2)。
%
% 输出标准形式：
%   M(q) qdd + C(q,qd) qd + G(q) = tau
%
% 说明：
%   1) 本函数采用拉格朗日法与几何雅可比自动构造符号形式 M、C、G。
%   2) 拓扑关系完全来自 LP.BB、LP.J_type、LP.Rp/Rd/Pp/Pd、LP.T_L 等字段；
%      分支构型会自动沿父节点递推。
%   3) 输出维度与 SV.q 保持一致（LP.num_q x LP.num_q）。非转动模块对应的行列为 0。
%   4) DynParam(i).com 默认表达在第 i 个模块的本体坐标系：R 模块为关节后坐标系，
%      L 模块为其远端坐标系（与现有 SV.AA/SV.RR 定义一致）。

if nargin < 4 || isempty(gravity)
    gravity = [0; 0; -9.81];
end
gravity = gravity(:);

n = LP.num_q;
DynParam = normalizeDynParam(DynParam, n);

% 默认生成标准解析动力学模型；即使 SV_generate 初始化的是数值零向量，
% 也会自动提升为符号 q、qd、qdd，便于直接获得 M(q)、C(q,qd)、G(q)。
useSymbolic = true;
q = symColumn(SV, 'q', n);
qd = symColumn(SV, 'qd', n);

[origin, orient, zAxis, ancestors, DynInfo] = forwardDynamicsFrames(LP, q, useSymbolic);
DynInfo.missing = detectMissingDynParam(DynParam, n);
DynInfo.gravity = gravity;
DynInfo.coordinate_note = ['DynParam(i).com is interpreted in the body frame used by ' ...
    'SV.AA/SV.RR: post-joint frame for R modules and distal frame for L modules.'];

M = zerosLike(n, n, useSymbolic);
G = zerosLike(n, 1, useSymbolic);
U = scalarZero(useSymbolic);

for i = 1:n
    [mass_i, com_i, inertia_i] = readDynParam(DynParam(i), useSymbolic);
    p_com = origin(:,i) + orient(:,:,i) * com_i;

    Jv = zerosLike(3, n, useSymbolic);
    Jw = zerosLike(3, n, useSymbolic);
    chain = ancestors{i};
    for k = chain(:)'
        if LP.J_type(k) == 'R'
            Jw(:,k) = zAxis(:,k);
            Jv(:,k) = cross(zAxis(:,k), p_com - origin(:,k));
        end
    end

    I_world = orient(:,:,i) * inertia_i * orient(:,:,i).';
    M = M + mass_i * (Jv.' * Jv) + Jw.' * I_world * Jw;
    U = U - mass_i * gravity.' * p_com;
end

for i = 1:n
    G(i) = simplify(diff(U, q(i)));
end

M = simplify(M);
C = christoffelMatrix(M, q, qd);
G = simplify(G);

tau = M * getVector(SV, 'qdd', n, useSymbolic, 'qdd') + C * qd + G;
DynInfo.active_joint_idx = find(LP.J_type == 'R');
DynInfo.passive_or_link_idx = find(LP.J_type ~= 'R');
end

function DynParam = normalizeDynParam(DynParam, n)
if nargin < 1 || isempty(DynParam)
    DynParam = struct([]);
end
for i = 1:n
    if numel(DynParam) < i || ~isfield(DynParam, 'mass') || isempty(DynParam(i).mass)
        DynParam(i).mass = NaN;
    end
    if ~isfield(DynParam, 'com') || isempty(DynParam(i).com)
        DynParam(i).com = [NaN NaN NaN];
    end
    if ~isfield(DynParam, 'inertia') || isempty(DynParam(i).inertia)
        DynParam(i).inertia = [NaN NaN NaN NaN NaN NaN];
    end
end
end

function missing = detectMissingDynParam(DynParam, n)
missing = struct('mass', [], 'com', [], 'inertia', []);
for i = 1:n
    if any(isnan(doubleOrNan(DynParam(i).mass)))
        missing.mass(end+1) = i; %#ok<AGROW>
    end
    if any(isnan(doubleOrNan(DynParam(i).com)))
        missing.com(end+1) = i; %#ok<AGROW>
    end
    if any(isnan(doubleOrNan(DynParam(i).inertia)))
        missing.inertia(end+1) = i; %#ok<AGROW>
    end
end
end

function value = doubleOrNan(value)
try
    value = double(value);
catch
    value = NaN;
end
end

function [mass_i, com_i, inertia_i] = readDynParam(param, useSymbolic)
mass_i = replaceUnknown(param.mass, 0);
com_i = replaceUnknown(param.com, 0);
inertia_v = replaceUnknown(param.inertia, 0);
com_i = reshape(com_i, 3, 1);
inertia_v = reshape(inertia_v, 1, 6);
inertia_i = [inertia_v(1), inertia_v(4), inertia_v(6); ...
             inertia_v(4), inertia_v(2), inertia_v(5); ...
             inertia_v(6), inertia_v(5), inertia_v(3)];
if useSymbolic
    mass_i = sym(mass_i);
    com_i = sym(com_i);
    inertia_i = sym(inertia_i);
end
end

function value = replaceUnknown(value, fillValue)
if isempty(value)
    value = fillValue;
    return;
end
try
    mask = isnan(value);
    value(mask) = fillValue;
catch
    % Symbolic values are kept as-is unless they are convertible NaN.
end
end

function q = symColumn(SV, fieldName, n)
if isfield(SV, fieldName) && isa(SV.(fieldName), 'sym')
    q = SV.(fieldName)(:);
else
    q = sym(fieldName, [n 1], 'real');
end
end

function value = getVector(SV, fieldName, n, useSymbolic, symName)
if isfield(SV, fieldName) && ~isempty(SV.(fieldName))
    value = SV.(fieldName)(:);
else
    value = zerosLike(n, 1, useSymbolic);
end
if useSymbolic && ~isa(value, 'sym')
    value = sym(symName, [n 1], 'real');
end
end

function [origin, orient, zAxis, ancestors, DynInfo] = forwardDynamicsFrames(LP, q, useSymbolic)
n = LP.num_q;
origin = zerosLike(3, n, useSymbolic);
orient = zerosLike(3, 3, n, useSymbolic);
zAxis = zerosLike(3, n, useSymbolic);
ancestors = cell(1, n);
DynInfo.parent = LP.BB(:).';
DynInfo.module = LP.module(:).';
DynInfo.joint_type = LP.J_type;

for i = 1:n
    parent = LP.BB(i);
    alignT = makeT(cz(LP.align(i)), [0;0;0], useSymbolic);
    if parent == 0
        baseT = makeT(LP.RBcp(:,:,LP.SN(i)), LP.PBcp(:,LP.SN(i)), useSymbolic);
        T_parent_distal = baseT;
        ancestors{i} = i;
    else
        T_parent_distal = makeT(orient(:,:,parent), origin(:,parent), useSymbolic);
        if LP.J_type(parent) == 'R'
            T_parent_distal = T_parent_distal * makeT(LP.Rd(:,:,LP.module(parent)), LP.Pd(:,LP.module(parent)), useSymbolic);
        end
        ancestors{i} = [ancestors{parent}, i];
    end

    if LP.J_type(i) == 'R'
        T_joint = T_parent_distal * alignT * makeT(LP.Rp(:,:,LP.module(i)), LP.Pp(:,LP.module(i)), useSymbolic);
        zAxis(:,i) = T_joint(1:3,1:3) * [0;0;1];
        T_body = T_joint * makeT(cz(q(i)), [0;0;0], useSymbolic);
    else
        T_body = T_parent_distal * alignT * symOrDouble(LP.T_L(:,:,LP.module(i)), useSymbolic);
        zAxis(:,i) = T_body(1:3,1:3) * [0;0;1];
    end
    origin(:,i) = T_body(1:3,4);
    orient(:,:,i) = T_body(1:3,1:3);
end
DynInfo.ancestors = ancestors;
end

function T = makeT(R, p, useSymbolic)
T = zerosLike(4, 4, useSymbolic);
T(1:3,1:3) = symOrDouble(R, useSymbolic);
T(1:3,4) = symOrDouble(p(:), useSymbolic);
T(4,4) = 1;
end

function C = christoffelMatrix(M, q, qd)
n = length(q);
C = sym(zeros(n, n));
for i = 1:n
    for j = 1:n
        cij = sym(0);
        for k = 1:n
            cij = cij + 0.5 * (diff(M(i,j), q(k)) + diff(M(i,k), q(j)) - diff(M(j,k), q(i))) * qd(k);
        end
        C(i,j) = simplify(cij);
    end
end
end

function z = zerosLike(varargin)
useSymbolic = varargin{end};
dims = cell2mat(varargin(1:end-1));
if useSymbolic
    z = sym(zeros(dims));
else
    z = zeros(dims);
end
end

function value = scalarZero(useSymbolic)
if useSymbolic
    value = sym(0);
else
    value = 0;
end
end

function value = symOrDouble(value, useSymbolic)
if useSymbolic
    value = sym(value);
else
    value = double(value);
end
end

%% 总体函数【不对 LP SV 更改】

function [M, C, G] = calc_MCG_0612(LP, SV, q)
g = [0; 0; -9.81];
idx_q = LP.R_idx(1:LP.num_joint);
SV.q(idx_q) = q(:);
SV = calc_aa_0318(LP, SV);
SV = calc_pos_0318(LP, SV);

rb = calc_Dy_Para_0612(LP);
[M, G] = calc_MG(LP, SV, rb, q(:), g);
C = calc_C(LP, SV, rb, q(:), SV.qd(idx_q), g);

end

%%  函数1
function rb = calc_Dy_Para_0612(LP)
[sub_module, sub_align] = split_joint_chain(LP.module, LP.align);
rb(LP.num_joint) = struct('m', [], 'rc', [], 'I', []);
for i = 1:LP.num_joint-1
    [rb(i).m, rb(i).rc, rb(i).I] = calc_rigid_body_params_0318(sub_module{i}, sub_align{i});
end
module_end = LP.module(end);
rb(end).m = LP.module_mass_dist(module_end);
rb(end).rc = LP.module_COM_dist(:,module_end);
rb(end).I = LP.module_inertia_dist(:,:,module_end);
end

%%  函数2
function [M, G] = calc_MG(LP, SV, rb, q, g)
idx_q = LP.R_idx(1:LP.num_joint);
SV.q(idx_q) = q;
SV = calc_aa_0318(LP, SV);
SV = calc_pos_0318(LP, SV);

M = zeros(LP.num_joint, LP.num_joint);
G = zeros(LP.num_joint, 1);

for i = 1:length(rb)
    joint_id = idx_q(i);
    A = SV.AA(:, 3*joint_id-2:3*joint_id);
    pc = SV.RR(:, joint_id) + A * rb(i).rc;
    Ic = A * rb(i).I * A';

    [Jv, Jw] = calc_jacobian_com(LP, SV, joint_id, pc);
    M = M + rb(i).m * (Jv' * Jv) + Jw' * Ic * Jw;
    G = G - Jv' * rb(i).m * g;
end

M = (M + M') / 2;
end

%%  函数3
function C = calc_C(LP, SV, rb, q, qd, g)
n = LP.num_joint;
dM = zeros(n, n, n);
h = 1e-6;

for k = 1:n
    dq = zeros(n, 1);
    dq(k) = h;
    [M1, ~] = calc_MG(LP, SV, rb, q + dq, g);
    [M2, ~] = calc_MG(LP, SV, rb, q - dq, g);
    dM(:, :, k) = (M1 - M2) / (2 * h);
end

C = zeros(n, n);
for i = 1:n
    for j = 1:n
        for k = 1:n
            C(i,j) = C(i,j) + 0.5 * (dM(i,j,k) + dM(i,k,j) - dM(j,k,i)) * qd(k);
        end
    end
end
end

%%  函数4
function [Jv, Jw] = calc_jacobian_com(LP, SV, body_joint_id, pc)
idx_q = LP.R_idx(1:LP.num_joint);
chain = joint_chain(LP, body_joint_id);
Ez = [0; 0; 1];
Jv = zeros(3, LP.num_joint);
Jw = zeros(3, LP.num_joint);

for j = 1:LP.num_joint
    joint_id = idx_q(j);
    if any(chain == joint_id)
        A = SV.AA(:, 3*joint_id-2:3*joint_id);
        z = A * Ez;
        Jv(:,j) = cross(z, pc - SV.RR(:, joint_id));
        Jw(:,j) = z;
    end
end
end

%%  函数5
function chain = joint_chain(LP, joint_id)
chain = [];
while joint_id ~= 0
    if LP.J_type(joint_id) == 'R'
        chain = [joint_id, chain]; %#ok<AGROW>
    end
    joint_id = LP.BB(joint_id);
end
end

%%

function verify_skew_Mdot_C(LP, SV, rb)

n = LP.num_joint;

% 随机状态
q  = rand(n,1)*2*pi;
qd = randn(n,1);

g = [0;0;-9.81];

eps = 1e-6;

% 当前 M
[M,~] = calc_MG(LP, SV, rb, q, g);

% -------- 求 Mdot ----------
q_plus  = q + qd*eps;
q_minus = q - qd*eps;

[M_plus,~]  = calc_MG(LP, SV, rb, q_plus, g);
[M_minus,~] = calc_MG(LP, SV, rb, q_minus, g);

Mdot = (M_plus - M_minus)/(2*eps);

% ---------- 求 C ----------
C = calc_C(LP, SV, rb, q, qd, g);

% ---------- 验证 ----------
S = Mdot - 2*C;

err = norm(S + S','fro');

fprintf('Skew symmetry error = %.3e\n', err);

end


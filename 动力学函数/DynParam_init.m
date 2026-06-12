function DynParam = DynParam_init(LP, defaultValue)
% DynParam_init  创建可扩展的动力学参数结构体模板。
%
%   DynParam = DynParam_init(LP)              使用 NaN 初始化未知参数。
%   DynParam = DynParam_init(LP, defaultValue) 使用指定值初始化所有参数。
%
% 返回字段：
%   DynParam(i).mass    = m_i;
%   DynParam(i).com     = [x_i, y_i, z_i];
%   DynParam(i).inertia = [Ixx Iyy Izz Ixy Iyz Ixz];

if nargin < 2
    defaultValue = NaN;
end

DynParam = repmat(struct('mass', defaultValue, ...
                         'com', defaultValue * ones(1, 3), ...
                         'inertia', defaultValue * ones(1, 6)), 1, LP.num_q);
end

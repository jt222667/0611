function [m_rb, rc_rb, I_rb] = calc_rigid_body_params_0318(module, align)
%CALC_RB_DYNAMICS_0318 计算相邻两个关节模块之间新刚体的动力学参数
%   module = [Joint_i Joint_j] 或 [Joint_i Link_k Joint_j]
%   align  为与 module 对应的连接方式参数。
%   输出 m_rb、rc_rb、I_rb 均表示在 Joint_i 的关节局部坐标系下。

RP_data = Module_Lib();
install = ones(1, length(module));
sequence = 0:length(module)-1;

LP = LP_generate(module, install, align, sequence, RP_data);
SV = SV_generate(LP);
SV = calc_aa_0318(LP, SV);
SV = calc_pos_0318(LP, SV);

A_i = SV.AA(:, 1:3);
r_i = SV.RR(:, 1);

m_part = zeros(1, length(module));
rc_part = zeros(3, length(module));
I_part = zeros(3, 3, length(module));
R_part = zeros(3, 3, length(module));

% Joint_i 的远端部分，质心和惯性矩阵已在 Joint_i 关节局部坐标系中给出。
joint_i = module(1);
m_part(1) = LP.module_mass_dist(joint_i);
rc_part(:,1) = LP.module_COM_dist(:, joint_i);
I_part(:,:,1) = LP.module_inertia_dist(:,:, joint_i);
R_part(:,:,1) = eye(3);

if length(module) == 3
    % 中间连杆模块：由 calc_aa_0318/calc_pos_0318 得到连杆远端位姿，
    % 再反推出连杆近端坐标系下质心在 Joint_i 局部坐标系中的位置。
    link_k = module(2);
    A_link_dist = SV.AA(:, 4:6);
    r_link_dist = SV.RR(:, 2);
    T_link = LP.T_L(:,:, link_k);
    A_link_prox = A_link_dist * T_link(1:3,1:3)';
    r_link_prox = r_link_dist - A_link_prox * T_link(1:3,4);

    m_part(2) = LP.module_mass(link_k);
    rc_part(:,2) = A_i' * (r_link_prox + A_link_prox * LP.module_COM(:, link_k) - r_i);
    I_part(:,:,2) = LP.module_inertia(:,:, link_k);
    R_part(:,:,2) = A_i' * A_link_prox;
end

% Joint_j 的近端部分：由 calc_aa_0318/calc_pos_0318 得到 Joint_j 位姿，
% 再反推出 Joint_j 近端坐标系下质心在 Joint_i 局部坐标系中的位置。
j = length(module);
joint_j = module(j);
A_j = SV.AA(:, 3*j-2:3*j);
r_j = SV.RR(:, j);
A_j_prox = A_j * LP.Rp(:,:, joint_j)';
r_j_prox = r_j - A_j_prox * LP.Pp(:, joint_j);

m_part(j) = LP.module_mass_prox(joint_j);
rc_part(:,j) = A_i' * (r_j_prox + A_j_prox * LP.module_COM_prox(:, joint_j) - r_i);
I_part(:,:,j) = LP.module_inertia_prox(:,:, joint_j);
R_part(:,:,j) = A_i' * A_j_prox;

m_rb = sum(m_part);
rc_rb = rc_part * m_part' / m_rb;

I_rb = zeros(3,3);
for k = 1:length(module)
    d = rc_part(:,k) - rc_rb;
    I_rb = I_rb + R_part(:,:,k) * I_part(:,:,k) * R_part(:,:,k)' ...
        + m_part(k) * ((d' * d) * eye(3) - d * d');
end
end

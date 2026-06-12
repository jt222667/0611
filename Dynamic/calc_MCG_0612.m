%% 总体函数【不对 LP SV 更改】

function [M, C, G] = calc_MCG_0612(LP, SV, q, qd)
g = [0; 0; -9.81];
idx_q = LP.R_idx(1:LP.num_joint);
SV.q(idx_q) = q(:);
SV.qd(idx_q) = qd(:);
SV = calc_aa_0318(LP, SV);
SV = calc_pos_0318(LP, SV);

[M, G] = calc_MG(LP, SV, q(:), g);
C = calc_C(LP, SV, q(:), SV.qd(idx_q), g);

end

%%  函数1
function [M, G] = calc_MG(LP, SV, q, g)
idx_q = LP.R_idx(1:LP.num_joint);
SV.q(idx_q) = q;
SV = calc_aa_0318(LP, SV);
SV = calc_pos_0318(LP, SV);

M = zeros(LP.num_joint, LP.num_joint);
G = zeros(LP.num_joint, 1);

for i = 1:length(LP.rb)
    joint_id = idx_q(i);
    A = SV.AA(:, 3*joint_id-2:3*joint_id);
    pc = SV.RR(:, joint_id) + A * LP.rb(i).rc;
    Ic = A * LP.rb(i).I * A';

    [Jv, Jw] = calc_jacobian_com(LP, SV, joint_id, pc);
    M = M + LP.rb(i).m * (Jv' * Jv) + Jw' * Ic * Jw;
    G = G - Jv' * LP.rb(i).m * g;
end

M = (M + M') / 2;
end

%%  函数2
function C = calc_C(LP, SV, q, qd, g)
n = LP.num_joint;
dM = zeros(n, n, n);
h = 1e-6;

for k = 1:n
    dq = zeros(n, 1);
    dq(k) = h;
    [M1, ~] = calc_MG(LP, SV, q + dq, g);
    [M2, ~] = calc_MG(LP, SV, q - dq, g);
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

%%  函数3
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

%%  函数4
function chain = joint_chain(LP, joint_id)
chain = [];
while joint_id ~= 0
    if LP.J_type(joint_id) == 'R'
        chain = [joint_id, chain]; %#ok<AGROW>
    end
    joint_id = LP.BB(joint_id);
end
end


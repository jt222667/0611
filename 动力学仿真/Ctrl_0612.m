function [sys,x0,str,ts] = chap2_1ctrl(t,x,u,flag)

switch flag
    case 0
        [sys,x0,str,ts]=mdlInitializeSizes;
    case 3
        sys=mdlOutputs(t,x,u);
    case {2,4,9}
        sys=[];
    otherwise
        error(['Unhandled flag = ',num2str(flag)]);
end

function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumOutputs     = 7;
sizes.NumInputs      = 28;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];

function sys=mdlOutputs(t,x,u)
% 输入分解
R = u(1:7);         % 7个设置位置
dr = u(22:28);      % 7个设置速度
q = u(8:14);        % 7个实际位置
dq = u(15:21);      % 7个实际速度
ddqd = -R;
% 计算误差
e = R - q;
de = dr - dq;

F = 5
if F==1 % 前馈
    [M,C]=compute_symbolic_dynamics(R,dr);
    tol = M*(-R) + C ;
elseif F==2 % PD
    % Kp = diag([700, 600, 500, 500, 400, 300, 100]);
    % Kd = diag([70, 60, 50, 50, 40, 30, 10]);
    Kp = diag([200, 200, 200, 200, 200, 200, 200]);
    Kd = diag([20, 20, 20, 20, 20, 20, 20]);
    tol = Kp*e + Kd*de;
elseif F==3 % PD + 前馈
    [M,C]=compute_symbolic_dynamics(R,dr);
    % Kp = diag([700, 600, 500, 500, 400, 300, 100]);
    % Kd = diag([70, 60, 50, 50, 40, 30, 10]);
    Kp = diag([200, 200, 200, 200, 200, 200, 200]);
    Kd = diag([20, 20, 20, 20, 20, 20, 20]);
    tol = M*(-R) + C + Kp*e + Kd*de;
elseif F==4 % SMC
    [M,C]=compute_symbolic_dynamics(R,dr);
    M0=0.8*M;
    dM=M0-M;
    P = diag([20, 20, 20, 20, 20, 20, 20]);                                            % 滑模面参数矩阵
    s = de + P * e;                                                                    % 滑模面 s = de + P*e
    temp = abs(dM)*abs(ddqd + P*de) + abs(0.2*C) + 0.10;
    gama = diag([temp(1) temp(2)  temp(3) temp(4) temp(5) temp(6) temp(7)]);           % 切换增益矩阵
    tol = M0*(-R + P*de) + 0.8*C + gama * sign(s);                                     % 控制力矩
elseif F==5   % NFTSMC
    [M,C] = compute_symbolic_dynamics(R,dr);
    alpha = 0.5*eye(7);
    beta  = 0.8*eye(7);
    m = 5/3;
    n = 9/7;
    K1 = 80*eye(7);
    K2 = 30*eye(7);
    eps = 1e-2;
    e  = -e;
    de = -de;
    % ---------- NFTSM 面 ----------
    s = e + alpha*((abs(e)+eps).^m).*sign(e) ...
        + beta *((abs(de)+eps).^n).*sign(de);
    % ---------- 导数项（稳定化） ----------
    A = de + alpha*m*((abs(e)+eps).^(m-1)).*de;
    Bdiag = beta*n*((abs(de)+eps).^(n-1));
    % 关键：防止B接近0
    Bdiag = max(Bdiag, 0.05);
    B = diag(Bdiag);
    % ---------- 趋近律（限幅） ----------
    ds = -K1*s - K2*((abs(e)+eps).^0.8).*sign(s);
    ds = max(min(ds, 30), -30);
    % ---------- 控制律（核心修正点） ----------
    tol = M * (B \ (ds - A) - R) + C;
end

sys = tol;

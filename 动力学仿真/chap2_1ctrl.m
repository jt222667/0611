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

% F=1;

% if F==1 % PD + 前馈，M C由实际角度，实际速度计算
%     [M,C]=compute_symbolic_dynamics(q,dq);
%     Kp = diag([700, 600, 500, 500, 400, 300, 100]);
%     Kd = diag([70, 60, 50, 50, 40, 30, 10]);
%     tol = M*(-R) + C + Kp*e + Kd*de;
% elseif F==2 % PD + 前馈，M C由目标角度，实际速度计算
%     [M,C]=compute_symbolic_dynamics(R,dr);
%     Kp = diag([700, 600, 500, 500, 400, 300, 100]);
%     Kd = diag([70, 60, 50, 50, 40, 30, 10]);
%     tol = M*(-R) + C +Kp*e + Kd*de;
% elseif F==3 % PD + 前馈，M C由目标角度，实际速度计算
%     y=compute2(R,dr,-R);
%     Kp = diag([700, 600, 500, 500, 400, 300, 100]);
%     Kd = diag([70, 60, 50, 50, 40, 30, 10]);
%     tol = Kp*e + Kd*de + y;
% elseif F==4
%     % 基于名义模型的常规滑模控制--用实际位置、实际速度计算M C
%     [M,C]=compute_symbolic_dynamics(q,dq);
%     M0=0.8*M;
%     dM=M0-M;
%     P = diag([20, 20, 20, 20, 20, 20, 20]);                                            % 滑模面参数矩阵
%     s = de + P * e;                                                                    % 滑模面 s = de + P*e
%     temp = abs(dM)*abs(ddqd + P*de) + abs(0.2*C) + 0.10;
%     gama = diag([temp(1) temp(2)  temp(3) temp(4) temp(5) temp(6) temp(7)]);           % 切换增益矩阵
%     tol = M0*(ddqd + P*de) + 0.8*C + gama * sign(s);                                   % 控制力矩
% elseif F==5
%     % 基于名义模型的常规滑模控制--用目标位置、目标速度计算M C
%     [M,C]=compute_symbolic_dynamics(R,dr);
%     M0=0.8*M;
%     dM=M0-M;
%     P = diag([20, 20, 20, 20, 20, 20, 20]);                                             % 滑模面参数矩阵
%     s = de + P * e;                                                                     % 滑模面 s = de + P*e
%     temp=abs(dM)*abs(ddqd+P*de)+abs(0.2*C)+0.10;
%     gama=diag([temp(1) temp(2)  temp(3) temp(4) temp(5) temp(6) temp(7)]);              % 切换增益矩阵
%     tol=M0*(ddqd+P*de)+0.8*C+gama*sign(s);                                              % 控制力矩
% elseif F==6
%     % 指数趋近率
%     tic;                     % 开始计时
%     %     [M,C]=compute_symbolic_dynamics(q,dq);
%     [M, C, ~] = test_1023_calculate_dynamics_single(q, dq);
% 
%     elapsedTime = toc;        % 获取耗时
%     disp(['compute_symbolic_dynamics 耗时：', num2str(elapsedTime), ' 秒']);
%     k = 10;                                                                             % 设计参数：指数趋近增益
%     epsilon = 10.0;                                                                      % 设计参数：切换增益
%     P = diag([20, 20, 20, 200, 200, 20, 200]);                                          % 滑模面参数矩阵
%     s = de + P * e;
%     S_dot = -k * s - epsilon * sign(s);                                                 % 指数趋近律
%     tol = M*(ddqd + P*de) + C - M * S_dot;                                              % 控制律
% elseif F==7
%     %     [M,C]=compute_symbolic_dynamics(q,dq);
%     test_1023_system_init_single();
%     [M, C, ~] = test_1023_calculate_dynamics_single(q, dq);
%     tol = M*ddqd + C ;                                              % 控制律
% end

sys = tol;

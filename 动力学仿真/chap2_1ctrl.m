function [sys,x0,str,ts] = chap2_1ctrl(t,x,u,flag)
%CHAP2_1CTRL 7 自由度关节空间 PD 控制器（无前馈）

switch flag
    case 0
        [sys,x0,str,ts] = mdlInitializeSizes;
    case 3
        sys = mdlOutputs(u);
    case {1,2,4,9}
        sys = [];
    otherwise
        error(['Unhandled flag = ', num2str(flag)]);
end
end

function [sys,x0,str,ts] = mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 7;
sizes.NumInputs      = 28;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0  = [];
str = [];
ts  = [0 0];
end

function sys = mdlOutputs(u)
q_D  = u(1:7);      % 期望关节位置
q_D_dot = u(22:28);    % 期望关节速度
q_D_dot_dot = -q_D;    % 期望关节速度

LP = evalin('base', 'LP');
SV = evalin('base', 'SV');

%% 前馈
[M_ctrl,C_ctrl,G_ctrl] = calc_MCG_0612_mex(LP, SV, q_D, q_D_dot);
tau = M_ctrl * q_D_dot_dot + C_ctrl * q_D_dot + G_ctrl;
sys = tau(:);

end

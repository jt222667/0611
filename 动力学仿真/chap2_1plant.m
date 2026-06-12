%S-function for continuous state equation
function [sys,x0,str,ts]=chap2_1plant(t,x,u,flag)
% persistent M_fun C_fun

switch flag

    case 0
        [sys,x0,str,ts]=mdlInitializeSizes;
    case 1
        sys=mdlDerivatives(t,x,u);
    case 3
        sys=mdlOutputs(t,x,u);
    case {2, 4, 9 }
        sys = [];
    otherwise
        error(['Unhandled flag = ',num2str(flag)]);
end

function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 14;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 14;
sizes.NumInputs      =7;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0 = [0 0 0 0 0 0 0 1 1 1 1 1 1 1]';

str=[];
ts=[0 0];

function sys=mdlDerivatives(t,x,u)
q=x(1:7);
dq=x(8:14);



tol=u(1:7);
S=M \ (tol - C);

sys(1:7)=x(8:14);
sys(8:14)=S(1:7);

function sys=mdlOutputs(t,x,u)
sys=x;
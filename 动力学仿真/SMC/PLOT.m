%% x1~x7存入cell数组
x = {x1,x2,x3,x4,x5,x6,x7};
% 全局字体设置，字号/字体修改一处即可全局生效
fontSize = 14;  
fontName = '宋体';  

%% ================= 位置跟踪 =================
figure(1)
box on;
for i = 1:7
    subplot(7,1,i)
    plot(t,x{i}(:,1),'r','LineWidth',2)
    hold on
    plot(t,x{i}(:,2),'b','LineWidth',2)
    hold off
    ylabel(['关节',num2str(i)],'FontSize',fontSize,'FontName',fontName)
    % 坐标轴刻度数字统一为宋体+指定字号
    set(gca,'FontSize',fontSize,'FontName',fontName)
    if i == 1
        % 图例：宋体 + 无边框
        legend('输入轨迹','实际轨迹',...
            'FontSize',fontSize,'FontName',fontName,'Box','off')
    end
end
xlabel('时间(s)','FontSize',fontSize,'FontName',fontName)


%% ================= 跟踪误差 =================
figure(2)
box on;
hold on
for i = 1:7
    plot(t,x{i}(:,1)-x{i}(:,2),'LineWidth',2)
end
xlabel('时间(s)','FontSize',fontSize,'FontName',fontName)
ylabel('误差(rad)','FontSize',fontSize,'FontName',fontName)
% 图例：宋体 + 无边框
legend('关节1','关节2','关节3','关节4','关节5','关节6','关节7',...
    'FontSize',fontSize,'FontName',fontName,'Box','on')
set(gca,'FontSize',fontSize,'FontName',fontName)


%% ================= 力矩 =================
figure(3)
box on;
hold on
for i = 1:7
    plot(t,tol(:,i),'LineWidth',2)
end
xlabel('时间(s)','FontSize',fontSize,'FontName',fontName)
ylabel('关节力矩(rad)','FontSize',fontSize,'FontName',fontName)
% 图例：宋体 + 无边框
legend('关节1','关节2','关节3','关节4','关节5','关节6','关节7',...
    'FontSize',fontSize,'FontName',fontName,'Box','on')
set(gca,'FontSize',fontSize,'FontName',fontName)
function [u] = read_input()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
a = get_param('qbot2/dist', 'RuntimeObject');
b = get_param('qbot2/ang', 'RuntimeObject');
u= [a.InputPort(1).Data;b.InputPort(1).Data];
% u=u-temp;
% if u(2)~=0
%     u=[(u(1)+u(2))/0.1;(u1(1)-u1(2))/5.05];
% end
end



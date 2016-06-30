function [u] = read_encoder()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
a = get_param('qbot2/dist', 'RuntimeObject');
b = get_param('qbot2/ang', 'RuntimeObject');
u= [a.InputPort(1).Data;b.InputPort(1).Data]
end



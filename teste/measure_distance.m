function [v] = measure_distance(room,x)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
v=zeros(5,1);
for i=-2:1:2
    ang=45*i;
    p=nearest(room,[x(1);x(2);x(3)+ang]);
    v(i+3)=sqrt((p(1)-x(1))^2+(p(2)-x(2))^2); 
end
end


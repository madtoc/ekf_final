function [x,P] = k_pred2(x,P,u,dt)
%UNTITLED13 Summary of this function goes here
%   Detailed explanation goes here
    if u(1)<0
        tmp=1;
    else
        tmp=-1;
    end
    theta = x(3)*pi/180;
    M= [0.0001^2 0; 0 0.0001^2];
    Q = [-0.0005*tmp;-0.0005;0.000];
    a=theta+u(2);
    D=u(1);
    T=u(2)*180/pi;
    f=[D*cos(a); D*sin(a); T];
    
    F = [[1, 0, -D*sin(a)],
        [0, 1, D*cos(a)],
        [0, 0, 1]];
    
    V = [[cos(a), -D*sin(a)],
        [sin(a), D*cos(a)],
        [0, 1]];
    
    x=x + f  +Q;
    P= F*P*transpose(F) + V*M*transpose(V)
    x(3)=mod(x(3),360)
end


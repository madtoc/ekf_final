function [x,P] = k_pred(x,P,u,dt)
%UNTITLED13 Summary of this function goes here
%   Detailed explanation goes here
    %r=0.036/2;
    d=0.2525;
    r2d=180/pi;
    d2r=pi/180;
    theta = x(3)*d2r;
    M= [0.01^2 0; 0 0.01^2];
    Q = [0.001;-0.004;0.00002];
    B= [[dt*cos(theta)/2, dt*cos(theta)/2],
       [dt*sin(theta)/2,  dt*sin(theta)/2],
       [r2d*dt/d,  -r2d*dt/d]];
    F = [[1, 0, -dt*(u(1)*sin(theta)/2 -u(1)*sin(theta)/2)],
        [0, 1, dt*(u(1)*cos(theta)/2 + u(2)*cos(theta)/2)],
        [0, 0, 1]];
    
    V = [[dt*cos(theta)/2, dt*cos(theta)/2],
        [dt*sin(theta)/2, dt*sin(theta)/2],
        [r2d*dt/d, -r2d*dt/d]];
    
    x=x + B*u; + Q;
    P= F*P*transpose(F) + V*M*transpose(V);
    x(3)=mod(x(3),360);
end


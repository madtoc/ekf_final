function [ x,P ] = k_up(x,P,H,h,z)
%UNTITLED12 Summary of this function goes here
%   Detailed explanation goes here
    R = 0.0025;    
    n = length(z);
    I = eye(length(P));
    R = R*eye(n)    ;
    S = H * P * transpose(H) + R;
    K = P*transpose(H)*inv(S);
    y=z-h;
    x = x + K*y;
    x(3)=mod(x(3),360);
    I_KH = I - K*H    ;
    P = I_KH*P*transpose(I_KH) + K*R*transpose(K);

end


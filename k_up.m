function [ x,P ] = k_up(x,P,H,h,z)
%UNTITLED12 Summary of this function goes here
%   Detailed explanation goes here
    %R = ones(5,1)*0.0025;
    R = [0.0192935267139390,0.0482512105765177,0.0427594126596264,0.0615188227723853,0.0192934361401392];
    %R = [ 0.0025 0.01 0.0025 0.01 0.0025];
    n = length(z);
    I = eye(length(P));
    R = diag(R);
    S = H * P * transpose(H) + R;
    K = P*transpose(H)*inv(S);
    y=z-h;
    x = x + K*y;
    x(3)=mod(x(3),360);
    I_KH = I - K*H    ;
    P = I_KH*P*transpose(I_KH) + K*R*transpose(K);

end


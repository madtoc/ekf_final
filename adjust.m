function [ang] = adjust( data,dt)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
%data1=Vr
%data2=Vl
%data3=dist encoder
%data4=ang encoder
d=0.2525;
ang=0;
r2d=180/pi;
if data(1)~=data(2)
    d1=(data(1)+data(2))*dt/2
    fact=data(3)/d1
    ang=(data(1)-data(2))*dt*fact/d;
end
    
end


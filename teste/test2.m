addpath('C:\Users\MT\Dropbox\ROBO AUTONOMO\ext\ekf_final\');
%addpath('/Users/MT/Dropbox/ROBO AUTONOMO/ext/ekf_final/');
load grav1-150f-40esq-tras.mat
%u=data(:,1:2);
u=data(:,3:4);
for i=length(u):-1:2
u(i,1)=u(i)-u(i-1);
end
for i=1:length(u)
if u(i,2) == 0 && abs(u(i,1)) > 0
    u(i,2)=0;
end
end
u(:,1)=u(:,1)*0.001;
u(:,2)=u(:,2)*-1;
ir_raw=data(:,10:14);
mag=data(:,15:16);
hardI=[-27.884615384615387 8.538461538461538];
softI=[1.067765567765568 0.940322580645161];
mag=mag-repmat(hardI,length(mag),1);
mag(:,1)=mag(:,1)*softI(1);
mag(:,2)=mag(:,2)*softI(2);

mag(:,1)=mag(:,1)/max(abs(mag(:,1)));
mag(:,2)=mag(:,2)/max(abs(mag(:,2)));

ang=mod(-atan2(mag(:,1)*softI(1),mag(:,2)*softI(2))*(180/pi)+294,360);
dt=0.1;
x=[1;0.5;0];
P=[0.9 0 0; 0 1.1 0; 0 0 4]; 
room=[1.82 1.1];
%%
for i=1:length(u)
    
    %[zIR,zSonar,zMag,IR_raw] = read_sensors();
    zIR = IR_raw2measure(ir_raw(i,:))';
    [z,H,h] = Hz(room,x,zIR);
    if (~isempty(z))
       [x,P] = k_up(x,P,H,h,z);
    end
    [x,P]=k_pred2(x,P,u(i,:)',dt);
    circle2(x(1),x(2),room);
    arrow(x,room);
    grid on;
    pause(0.01)
    x
end
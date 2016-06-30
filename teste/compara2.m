h=720;
w=1200;
ang=0;
name='grav1-50giro';
px=1.1/h;

%figure('units','normalized','outerposition',[0 0 1 1])

figure(1)
hold on
xlim([0 w*px])
ylim([0 h*px])

%%
v=VideoReader(strcat('C:\Users\MT\Videos\',+name,'.mp4'));
vf=read(v);
nFrames=size(vf,4);
xr=zeros(nFrames,2);
for i=1:nFrames
   disp(i)
   I=imrotate(vf(:,:,:,i),-87.26);
   I=I(190:910,258:1488,:);
   %imshow(I);
   I =rgb2hsv(I,'InitialMagnification',50);
   mask=(I(:,:,3)>0.45).*I(:,:,1).*(I(:,:,2)>0.2);
   imB=mask(:,:,1)>0.1 & mask(:,:,1)<0.4;
   measurements = regionprops(imB, 'Centroid');
   centroids = cat(1,measurements.Centroid);
   dist=measure_distance([w h],[centroids ang])*px;
   %imshow(imB);
   if i==1
   plot(centroids(1)*px, (h-centroids(2))*px, 'x', 'MarkerSize', 20, 'LineWidth', 2);
   end
   
   plot(centroids(1)*px, (h-centroids(2))*px, 'ko', 'MarkerSize', 3, 'LineWidth', 1);
   pause(0.001)
   xr(i,:)=[centroids(1)*px (h-centroids(2))*px];
end
hold on
circle4(centroids(1)*px, (h-centroids(2))*px,[1.82 1.1])
xlabel('width (m)','fontsize',14)
ylabel('height (m)','fontsize',14)

%%
addpath('C:\Users\MT\Dropbox\ROBO AUTONOMO\ext\ekf_final\');
load(strcat(name,'.mat'))
u=data(:,3:4);
for i=length(u):-1:2
u(i,1)=u(i)-u(i-1);
end
u(:,1)=u(:,1)*0.001;
u(:,2)=u(:,2)*-1;
ir_raw=data(:,10:14);
dt=0.1;
x=[1.2;0.4;0];
P=[1.82 0 0; 0 1.1 0; 0 0 4]; 
room=[1.82 1.1];
xe=zeros(length(u),2);
for i=1:length(u)
    
    %[zIR,zSonar,zMag,IR_raw] = read_sensors();
    zIR = IR_raw2measure(ir_raw(i,:))';
    [z,H,h] = Hz(room,x,zIR);
    if (~isempty(z))
       [x,P] = k_up(x,P,H,h,z);
    end
    ang=adjust([data(i,1:2) u(i,1:2)],dt);
    [x,P]=k_pred2(x,P,[u(i,1) ang],dt);
    xe(i,:)=[x(1) x(2)];
    if i==1
    plot(x(1),x(2),'mx', 'MarkerSize', 20, 'LineWidth', 2)
    end
    plot(x(1),x(2),'ro', 'MarkerSize', 3, 'LineWidth', 1)
    pause(0.01)
end
hold on
circle3(x(1), x(2),[1.82 1.1])

figure(2)
hold on
a=(sqrt( (xr(:,1)-xe(:,1)).^2+(xr(:,2)-xe(:,2) ).^2))
plot(a)
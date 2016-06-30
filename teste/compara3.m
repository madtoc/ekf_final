clear all
clc
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
addpath('C:\Users\MT\Dropbox\ROBO AUTONOMO\ext\ekf_final\');
load(strcat(name,'.mat'))
u=data(:,1:2);
ir_raw=data(:,10:14);
dt=0.1;
x=[1;0.2;0];
P=[1.82 0 0; 0 1.1 0; 0 0 4]; 
room=[1.82 1.1];
%%
v=VideoReader(strcat('C:\Users\MT\Videos\',+name,'.mp4'));
vf=read(v);
nFrames=size(vf,4);
for i=1:nFrames-1
   figure(1)
   xlim([0 w*px])
   ylim([0 h*px])
   disp(i)
   I=imrotate(vf(:,:,:,i),-87.26);
   I=I(190:910,258:1488,:);
   %imshow(I);
   I =rgb2hsv(I,'InitialMagnification',50);
   mask=(I(:,:,3)>0.45).*I(:,:,1).*(I(:,:,2)>0.2);
   imB=mask(:,:,1)>0.1 & mask(:,:,1)<0.4;
   measurements = regionprops(imB, 'Centroid');
   centroids = cat(1,measurements.Centroid);
   %imshow(imB); 
   %plot(centroids(1)*px, (h-centroids(2))*px, 'k--*', 'MarkerSize', 3, 'LineWidth', 2);
   pause(0.001)
   xr(i,:)=[centroids(1)*px (h-centroids(2))*px];
       zIR = IR_raw2measure(ir_raw(i,:))';
    [z,H,h1] = Hz(room,x,zIR);
    if (~isempty(z))
       [x,P] = k_up(x,P,H,h1,z);
    end
    [x,P]=k_pred(x,P,u(i,:)',dt);
    xe(i,:)=[x(1) x(2)];
    %plot(x(1),x(2),'r--*', 'MarkerSize', 3, 'LineWidth', 5)
    circle4(centroids(1)*px, (h-centroids(2))*px,[1.82 1.1])
    hold on
    circle3(x(1), x(2),[1.82 1.1])
    pause(0.01)
    xlabel('width (m)','fontsize',14)
    ylabel('height (m)','fontsize',14)
    y1=get(gca,'YLim');
    x1=get(gca,'XLim')
    text(x1(2)/4,y1(2)+0.2,strcat('x=',num2str(xr(i,:))),'Interpreter','latex',...
   'VerticalAlignment','bottom',...
   'HorizontalAlignment','left')
    text(x1(2)/4,y1(2)+0.1,strcat('$$\hat{x}=$$',num2str(xe(i,:))),'Interpreter','latex',...
   'VerticalAlignment','bottom',...
   'HorizontalAlignment','left')
    r=sqrt((xe(:,1)-xr(:,1)).^2 + (xe(:,2)-xr(:,2)).^2);
    mse=sum(r)/length(r);
    text(x1(2)/1.5,y1(2)+0.15,strcat('$$MSE=$$',num2str(mse)),'Interpreter','latex',...
   'VerticalAlignment','bottom',...
   'HorizontalAlignment','left')
    hold off
        
    % gif utilities
    set(gcf,'color','w'); % set figure background to white
    drawnow;
    frame = getframe(1);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im,256);
    outfile = 'teste.gif';
 
    % On the first loop, create the file. In subsequent loops, append.
    
    if i==1
            imwrite(imind,cm,outfile,'gif','Loopcount',inf);
    else
            imwrite(imind,cm,outfile,'gif','WriteMode','append');
    end    
end



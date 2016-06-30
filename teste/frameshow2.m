
h=720;
w=1200;
ang=0;
px=1.1/h;
v=VideoReader('C:\Users\MT\Videos\02.mp4');
vf=read(v);
nFrames=size(vf,4);
figure('units','normalized','outerposition',[0 0 1 1])
for i=nFrames:nFrames
   disp(i)
   I=imrotate(vf(:,:,:,i),-87.26);
   I=I(190:910,258:1488,:);
   imshow(I);
   I =rgb2hsv(I,'InitialMagnification',50);
   mask=(I(:,:,3)>0.45).*I(:,:,1).*(I(:,:,2)>0.2);
   imB=mask(:,:,1)>0.1 & mask(:,:,1)<0.4;
   measurements = regionprops(imB, 'Centroid');
   centroids = cat(1,measurements.Centroid);
   dist=measure_distance([w h],[centroids ang])*px
   %imshow(imB); 
   hold on;
   plot(centroids(1), centroids(2), 'g+', 'MarkerSize', 20, 'LineWidth', 1);
   hold off;
   set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
   pause(0.001)
end
centroids*px
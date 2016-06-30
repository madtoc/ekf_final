
h=720;
w=1230;
ang=0;
px=1.1/h;
v=VideoReader('C:\Users\MT\Videos\02.mp4');
vf=read(v);
nFrames=size(vf,4)+1;
figure('units','normalized','outerposition',[0 0 1 1])
for i=230:nFrames
   v=VideoReader('C:\Users\MT\Videos\02.mp4');
   disp(i)
   I=imrotate(vf(:,:,:,i),-87.26);
   I=I(190:910,258:1488,:);
   imG=squeeze(I(:,:,2));
   imB=im2bw(imG,graythresh(imG));
   measurements = regionprops(imB, 'Centroid');
   centroids = cat(1,measurements.Centroid);
   dist=measure_distance([w h],[centroids ang])*px
   imshow(imB); 
   hold on;
   plot(centroids(1), centroids(2), 'r+', 'MarkerSize', 20, 'LineWidth', 1);
   hold off;
   set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
   pause(0.1)
end
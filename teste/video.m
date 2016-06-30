h=720;
w=1230;
dim=[w h];
ang=0;
px=1.1/h;
I = imread('1.png');
imG=squeeze(I(:,:,2));
imB=im2bw(imG,graythresh(imG));
measurements = regionprops(imB, 'Centroid');
imshow(imB,'InitialMagnification',50); 
centroids = cat(1,measurements.Centroid);
hold on;
plot(centroids(1), centroids(2), 'r+', 'MarkerSize', 20, 'LineWidth', 1);
hold off;
dist=measure_distance([w h],[centroids ang])*px
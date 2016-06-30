%%
image=a(:,:,:,1);
% define R, G and B components of required color
R = 120;
G = 185;
B = 74;
% extract R, G and B channels
channelR = image(:, :, 1);
channelG = image(:, :, 2);
channelB = image(:, :, 3);
% calculate gray image
gray = rgb2gray(image);
% calculate differences for each channels
dR = channelR - R;
dG = channelG - G;
dB = channelB - B;

% calculate overall distance from the given RGB color
d = dR .^ 2 + dG .^ 2 + dB .^ 2;

% create a mask by thresholding the differences
mask = d < 100;

% copy the gray values where the mask is true
channelR(mask) = gray(mask);
channelG(mask) = gray(mask);
channelB(mask) = gray(mask);

%copy channels into the RGB image
image2(:, :, 1) = channelR;
image2(:, :, 2) = channelG;
image2(:, :, 3) = channelB;
imshow(image2)
imshow(mask)

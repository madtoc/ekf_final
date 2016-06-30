function circle2(x,y,room)
clf
%d=0.34;
d=0.3;
r = d/2;
px = x-r;
py = y-r;
rectangle('Position',[px py d d],'Curvature',[1,1]);
rectangle('Position',[0 0 room(1) room(2)])
daspect([1,1,1])
xlim([-0.1 room(1)+0.1]);
ylim([-0.1 room(2)+0.1]);
end




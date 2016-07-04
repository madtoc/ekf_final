function [h] = real_dist(room,x)
    nsensor=5;
    ang=180/(nsensor-1);
    hzinho = @(x,y,p_x,p_y) sqrt( (p_x - x)^2 + (p_y - y)^2);
    theta=x(3)-90;
    h=zeros(5,1);
    n=[5 4 3 2 1];
    for i=1:5
        aux= mod(theta+ang*(n(i)-1),360);
        p= nearest(room,[x(1);x(2);aux]);
        h(i,1)= hzinho(x(1),x(2),p(1),p(2));
    end
    end
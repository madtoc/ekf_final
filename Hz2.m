function [z,H,h] = Hz2(room,x,zIR)
    nsensor=5;
    s_range=1.5;
    r=[0.10; 0.12; 0.12; 0.12; 0.10];
    H=[];
    h=[];
    z=[];
    p=[];
    ang=180/(nsensor-1);
    hzinho = @(x,y,p_x,p_y) sqrt( (p_x - x)^2 + (p_y - y)^2);
    Hzao = @(x,y,p_x,p_y) [(-p_x+x)/sqrt((p_x - x)^2 + (p_y - y)^2), (-p_y+y)/sqrt((p_x - x)^2 + (p_y - y)^2), 0];
    theta=90+x(3);
    
    n=find(zIR >0.2 & zIR<s_range );
    z=zIR(n)+r(n);
    
    
    for i=1:length(n)
        aux= mod(theta-ang*(n(i)-1),360);
        p= nearest(room,[x(1);x(2);aux]);
        H(i,:)= Hzao(x(1),x(2),p(1),p(2));
        h(i,1)= hzinho(x(1),x(2),p(1),p(2));
    end
    end


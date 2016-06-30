function [ ] = arrow( X,room )
theta=X(3)*pi/180;
xlim([0 room(1)]);
ylim([0 room(2)]);
y=sin(theta);
x=cos(theta);
a=sqrt(y^2+x^2);
x=x/10;
y=y/10;
h = annotation('arrow');
set(h,'parent', gca, ...
    'position', [X(1),X(2),x,y]);

end
x = 1:25; 
y = x+randi(25,1,25);


xx = x;
yy = y;
p = polyfit(xx, yy,2);
yx=polyval(p,xx);
figure;
hold on
plot(xx, yy, '*');
plot(x,yx)
hold off
r=corrcoef(xx,yy);
r_sq = r(2,1)*2;
disp(r_sq)
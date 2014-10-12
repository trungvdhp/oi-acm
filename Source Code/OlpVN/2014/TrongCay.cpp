#include <cstdio>
// Diem M nam trong 1 tam giác ABC neu dinh thuc cua cac cap vecto (AM,AC),(BM,BA),(CM,CB) cung dau
// vecto noi hai diem A,B là : AB=(xB-xA,yB-yA)
// dinh thuc cua hai vecto U,V là : det(U,V)= xU*yV - xV*yU

int get_min3(int a, int b, int c)
{
	if(b<a) a=b;
	if(c<a) a=c;
	
	return a;
}

int get_max3(int a, int b, int c)
{
	if(b>a) a=b;
	if(c>a) a=c;
	
	return a;
}

int sign(int a, int b, int c, int x, int y)
{
	int d=a*x+b*y+c;
	
	if(d<0) return -1;
	
	if(d>0) return 1;
	
	return 0;
}

bool is_inside(int d1, int d2, int d3)
{
	if((d1>0 && d2>0 && d3>0) || (d1<0 && d2<0 && d3<0)) return true;
	
	return false;
}

int main()
{
	int test;
	int x,y;
	int count;
	int xa,ya,xb,yb,xc,yc;
	int a1,b1,c1;
	int a2,b2,c2;
	int a3,b3,c3;
	int d1,d2,d3;
	int min_x, max_x, min_y, max_y;
	scanf("%d", &test);
	
	while(test--)
	{
		scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
		
		min_x=get_min3(xa,xb,xc);
		max_x=get_max3(xa,xb,xc);
		min_y=get_min3(ya,yb,yc);
		max_y=get_max3(ya,yb,yc);
		
		// U=AM=(xM-xA,yM-yA), V=AC=(xC-xA, yC-yA), d1=det(U, V)=(xM-xA)*(yC-yA)-(xC-xA)*(yM-yA)
		// d1=(yC-yA)*xM + (xA-xC)*yM - xA*(yC-yA) - yA*(xA-xC)
		a1=yc-ya;
		b1=xa-xc;
		c1=-xa*a1-ya*b1;
		
		a2=ya-yb;
		b2=xb-xa;
		c2=-xb*a2-yb*b2;
		
		a3=yb-yc;
		b3=xc-xb;
		c3=-xc*a3-yc*b3;
		
		count = 0;
		
		for(x=min_x; x<=max_x; x++)
			for(y=min_y; y<=max_y; y++)
			{
				d1=sign(a1, b1, c1, x, y);
				d2=sign(a2, b2, c2, x, y);
				d3=sign(a3, b3, c3, x, y);
				
				if(is_inside(d1, d2, d3))
					count++;
			}
		printf("%d\n", count);
	}
	return 0;
}

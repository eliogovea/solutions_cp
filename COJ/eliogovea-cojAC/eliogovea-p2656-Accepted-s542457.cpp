#include<cstdio>
#include<cmath>

int r,b;
double dis,a1,a2,b1,b2;

bool INT(double x)
{
	int k;
	if(x-(double)(int(x)) <= 1e-6)
	return 1;
	if(double(int(x)+1.0-x) <= 1e-6)
	return 1;

	return 0;
}

int main()
{
	scanf("%d%d",&r,&b);

	dis=(r/2.0+2.0)*(r/2.0+2.0)-4.0*(r+b);

	a1=(r/2.0+2.0+sqrt(dis))/2.0;
	b1=r/2.0+2.0-a1;
	a2=(r/2.0+2.0-sqrt(dis))/2.0;
	b2=r/2.0+2.0-a2;

	if(INT(a1) && INT(b1))
        printf("%.0lf %.0lf\n",a1,b1);
    else printf("%.0lf %.0lf\n",a2,b2);
}


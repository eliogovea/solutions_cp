#include<cstdio>
#include<cmath>

int r,b;
double dis,a1,b1;

int main()
{
	scanf("%d%d",&r,&b);

	dis=(r/2.0+2.0)*(r/2.0+2.0)-4.0*(r+b);

	a1=(r/2.0+2.0+sqrt(dis))/2.0;
	b1=r/2.0+2.0-a1;
    	printf("%.0lf %.0lf\n",a1,b1);
}


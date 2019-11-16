#include<cstdio>
#include<cmath>

int c;
double a;

int main()
{
	for(scanf("%d",&c); c--;)
	{
		scanf("%lf",&a);
		printf("%.4lf\n",12*a*a*( sin(M_PI/12.0)/(2.0*sqrt(2.0)) - M_PI/48.0 ));
	}
}

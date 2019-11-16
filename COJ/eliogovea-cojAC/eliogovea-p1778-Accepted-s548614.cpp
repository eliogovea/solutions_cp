#include<cstdio>

int n;
double a,b;

int main()
{
	for(scanf("%d",&n);n--;)
	{
		scanf("%lf%lf",&a,&b);
		printf("%.8lf\n",3.0*a*b/16.0);
	}
}

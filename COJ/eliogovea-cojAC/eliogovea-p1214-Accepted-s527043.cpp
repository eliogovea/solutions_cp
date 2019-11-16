#include<cstdio>
#include<cmath>

int c;
double a,s;

int main()
{
	for(scanf("%d",&c);c--;)
	{
		scanf("%lf%lf",&a,&s);
		printf("%.2lf\n",sqrt(s*s/4.0-a));
	}
	return 0;
}

#include <cstdio>
#include <cmath>

int n;
double l;

int main()
{
	for (scanf("%d", &n); n--;)
	{
		scanf("%lf", &l);
		printf("%.2lf\n", l * l - M_PI * l * l / 4.0);
	}
}

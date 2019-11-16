#include<cstdio>
#include<cmath>

double d;

int main()
{
    while(scanf("%lf",&d)!=EOF)
        printf("%.3lf\n",d*d*(M_PI-sqrt(3.0))/8.0);
    return 0;
}

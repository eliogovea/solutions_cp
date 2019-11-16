#include<cstdio>
#include<cmath>

int c,n;
double r,d[11];

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%d",&r,&n);
        printf("%.4lf\n",2.0*r*sin(M_PI/pow(2.0,n)));
    }
    return 0;
}

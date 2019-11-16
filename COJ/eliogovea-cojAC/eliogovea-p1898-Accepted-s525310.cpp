#include<cstdio>

int c;
double a,b,d;
int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%lf%lf",&a,&b,&d);
        printf("%.4lf\n",d/(a+b));
    }
    return 0;
}

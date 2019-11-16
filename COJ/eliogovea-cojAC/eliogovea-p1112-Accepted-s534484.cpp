#include<cstdio>
#include<cmath>

double r1,r2;

int main()
{
    while(scanf("%lf%lf",&r1,&r2)==2)
    {
        double AB=r1*(r1+r2)/(r2-r1);
        double a=asin(r1/AB)*360.0/M_PI;
        double m=(AB+r1)*r1/AB;
        printf("%.4lf %.2lf\n",m,a);
    }
    return 0;
}

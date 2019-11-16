#include<cstdio>
#include<cmath>
const double PI = 3.141592654;
const double c1=5.0*sqrt(3.0)/(32.0*PI*PI);
const double c2=7.0*sqrt(3.0)/(32.0*PI*PI);
int cas;
double a;

int main()
{
    scanf("%d",&cas);
    for(int i=1; i<=cas; i++)
    {
        scanf("%lf",&a);
        printf("Case %d\nRice: %.2lf\nBeans: %.2lf\n",i,c1*a*a,c2*a*a);

    }
}

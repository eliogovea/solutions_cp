#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int c;
double r,p,q,a;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%lf%lf",&r,&p,&q);
        a=abs(p-q);
        a=min(a,360.0-a);
        a*=M_PI/180.0;
        printf("%.3lf\n",r*r*(M_PI-a/2.0+sin(a)/2.0));
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cmath>

int c;
double n,r;

int main()
{
    scanf("%d",&c);
    for(int i=1; i<=c; i++)
    {
        scanf("%lf%lf",&r,&n);
        printf("Scenario #%d:\n%.3lf\n\n",i,r*sin(M_PI/n)/(1.0+sin(M_PI/n)));
    }
    return 0;
}

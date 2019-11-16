#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int c;
double ang,l;

int main()
{
    scanf("%d",&c);
    for(int i=0; i<c; i++)
    {
        scanf("%lf%lf",&l,&ang);
        ang*=M_PI/180.0;
        printf("%.3lf\n",l*l*sin(ang)-M_PI*(l*l*sin(ang)*sin(ang))/4.0);
    }
    return 0;
}

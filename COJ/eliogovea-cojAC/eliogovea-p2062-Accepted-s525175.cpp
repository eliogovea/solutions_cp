#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 20
using namespace std;

int c;
double a,b;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%lf",&a,&b);
        printf("%.4lf\n",sqrt(3)*b/(2.0*sin(a*M_PI/180.0)));
    }
    return 0;
}

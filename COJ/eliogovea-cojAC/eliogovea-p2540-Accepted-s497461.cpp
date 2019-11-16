#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double r1,r2;

int main()
{
    while(scanf("%lf%lf",&r1,&r2)!=EOF)
    {
        if(r2>r1)
        {
            double aux=r1;
            r1=r2;
            r2=aux;
        }
        r1/=2;
        r2/=2;
        printf("%.6lf\n",2*r1*(max(2*r1,r1+r2+2*sqrt(r1*r2))));
    }
    return 0;
}

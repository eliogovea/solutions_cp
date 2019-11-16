#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

double a,b,c,p,A,r;

int main()
{
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(2*max(a,max(b,c))==a+b+c)
            printf("The radius of the round table is: %.3f\n",0);
        else
        {
            p=(a+b+c)/2.0;
            A=sqrt(p*(p-a)*(p-b)*(p-c));
            r=(2.0*A)/(a+b+c);
            printf("The radius of the round table is: %.3f\n",r);
        }
    }
return 0;
}

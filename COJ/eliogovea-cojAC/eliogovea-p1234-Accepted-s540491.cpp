#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 3.141592653589793;

double r1,r2,a,n;

int main(){

    while(scanf("%lf%lf",&r1,&r2)==2)
    {
        a=asin(r2/(r1+r2));
        n=PI/a;

        if(n-(double)((int)n) < 1e-6)
            printf("%.4lf\n",(r1+r2)*(r1+r2)*sin(2.0*a)*((double)((int)n))/2.0);
        else if((double)(int(n))+1.0-n < 1e-6 )
            printf("%.4lf\n",(r1+r2)*(r1+r2)*sin(2.0*a)*((double)(int(n))+1.0)/2.0);
        else printf("No Solution\n");
    }

    }




#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 1010
using namespace std;

int n;
double c[MAXN],area,r,angle;
char sol[MAXN];

int main()
{
    scanf("%d%lf",&n,&r);

    for(int i=0; i<n; i++)
        scanf("%lf",&c[i]);

    sort(c,c+n);

    area=M_PI*r*r;

    for(int i=1; i<n; i++)
    {
        if(c[i-1]+2.0*r<=c[i])area+=M_PI*r*r;

        else
        {
            angle = acos((c[i]-c[i-1])/(2.0*r));
            area+= M_PI*r*r-2.0*r*r*angle+(c[i]-c[i-1])*r*sin(angle);
        }
    }

    sprintf(sol, "%.10lf", area);

	int cant=0;
    for(int i=0; cant<=6; i++)
    {
        char c=sol[i];
        if(c=='.')cant=1;
        if(cant)cant++;
        printf("%c",c);
    }
}

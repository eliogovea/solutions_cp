#include<cstdio>
#include<cmath>

int c;
double r,n,l;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%lf",&r,&n);
        l=2.0*r*sin(M_PI/n);
        if(l*l-r*r>0.0)
            printf("%.2lf\n",sqrt(l*l-r*r)*n*r*r*sin(2.0*M_PI/n)/6.0);
        else printf("impossible\n");
    }
}

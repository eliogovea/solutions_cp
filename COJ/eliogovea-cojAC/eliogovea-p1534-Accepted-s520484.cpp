#include<cstdio>
#include<cmath>
int n,c;
double l,r;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%d%lf",&n,&l);
        r=l/(sin(M_PI/(double)n)*2.0);
        if(l*l-r*r<=0)
            printf("-1\n");
        else
            printf("%.3lf\n",(double)n*r*r*sin(2.0*M_PI/double(n))*sqrt(l*l-r*r)/6.0);
    }
    return 0;
}

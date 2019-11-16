#include<cstdio>
#include<cmath>

int cas,n;
double p[10000][2],per,k,r;

double dist(double x1, double x2, double y1, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    for(scanf("%d",&cas);cas--;)
    {
        scanf("%lf%d",&r,&n);
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&p[i][0],&p[i][1]);

        per=dist(p[0][0],p[n-1][0],p[0][1],p[n-1][1]);
        for(int i=1; i<n; i++)
            per+=dist(p[i][0],p[i-1][0],p[i][1],p[i-1][1]);

        k=1.0-2.0*M_PI*r/per;

        if(k>0.0 && k<=1.0)
            printf("%.6lf\n",k);
        else printf("Not possible\n");
    }
    return 0;
}

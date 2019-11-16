#include<cstdio>
#include<cmath>
#include<limits.h>

int n;
double Xx,Xy,Yx,Yy,px,py,m;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    while(scanf("%lf%lf",&Xx,&Xy)!=EOF)
    {
        m=INT_MAX;
        scanf("%lf%lf%d",&Yx,&Yy,&n);
        while(n--)
        {
            scanf("%lf%lf",&px,&py);
            if(dist(Xx,Xy,px,py)+dist(px,py,Yx,Yy) < m)
                m=dist(Xx,Xy,px,py)+dist(px,py,Yx,Yy);
        }
        m+=dist(Xx,Xy,Yx,Yy);
        printf("%.4lf\n",m);
    }
    return 0;
}

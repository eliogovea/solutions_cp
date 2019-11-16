#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

double dist(double x1, double x2, double y1, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int n,ans;
double x,y,r,sx,sy,dm=1000000.0;

int main()
{
    while(scanf("%d",&n) && n)
    {
        scanf("%lf%lf",&sx,&sy);
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf%lf",&x,&y,&r);
            if(dist(sx,x,sy,y)-r<dm)
            {
                dm=dist(sx,x,sy,y)-r;
                ans=i;
            }
        }
        printf("%d\n",ans);
        dm=1000000.0;
        ans=0;
    }
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,t,H[1010];

struct point
{
    double x,y;
    bool operator<(const point &a)const
    {
        return (x!=a.x)?(x<a.x):(y<a.y);
    }
}p[1010],O;

double cross(point a, point b, point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double distc(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double dist(point a, point b)
{
	return sqrt(distc(a,b));
}

bool cmp (point a, point b ) {
    double cp = cross( p[0], a, b );
    if ( cp != 0 ) return cp > 0;
    else return distc( p[0], a ) < distc( p[0], b );
}

int main()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(p[i]<p[0])swap(p[i],p[0]);
    }

    p[n].x=0.0;
    p[n].y=0.0;
    if(p[n]<p[0])swap(p[n],p[0]);

    sort(p+1,p+n+1,cmp);

    for(int i=0; i<=n; i++)
    {
        while(t>1 && cross(p[H[t-2]],p[H[t-1]],p[i])<=0)t--;
        H[t++]=i;
    }

    O.x=0.0;
    O.y=0.0;

    double per=dist(p[H[0]],p[H[t-1]]);
    double mx=per;
	double mn=dist(p[H[0]],O);
    for(int i=1; i<t; i++)
	{
		mn=min(mn,dist(p[H[i]],O));
		per+=dist(p[H[i]],p[H[i-1]]);
	}

    double ans;
    if(mn==0.0)ans=per;
    else
    {
        ans=per+2.0*mn;
        for(int i=0; i<t; i++)
            ans=min(ans,per-dist(p[H[i]],p[H[(i+1)%t]])+dist(O,p[H[i]])+dist(O,p[H[(i+1)%t]]));
    }
    printf("%.2lf\n",ans+2.0);
    return 0;
}

#include<cstdio>
#include<cmath>

const double PI = 3.141592653589793116;
int t,n;
double r,ans;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lf",&r);
            if(i&1)ans+=r*r;
            else ans-=r*r;
        }
        if(!(n&1))ans=-ans;
        printf("%.9lf\n",PI*ans);
        ans=0;
    }
    return 0;
}

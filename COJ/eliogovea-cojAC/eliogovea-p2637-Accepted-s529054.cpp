#include<cstdio>

long long dp[1000001],x;
int a,b,c,n,q;

int main()
{
    //freopen("a.out","w",stdout);
    for(scanf("%d",&c);c--;)
    {
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&x);
            dp[i]=dp[i-1]+x;
        }

        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",dp[b+1]-dp[a]);
        }
        if(c)printf("\n");
    }
}

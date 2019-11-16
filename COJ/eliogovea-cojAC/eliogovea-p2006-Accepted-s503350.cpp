#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

struct bb
{
    ll w,h;
}b[2001];

int n,l;
ll dp[2001],mx,ac;

int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1; i<=n; i++)
        scanf("%lld%lld",&b[i].h,&b[i].w);

    for(int i=1; i<=n; i++)
    {
        mx=b[i].h,ac=b[i].w;
        dp[i]=dp[i-1]+mx;
        for(int j=i-1; j; j--)
        {
            ac+=b[j].w;
            if(ac>l)break;
            mx=max(mx,b[j].h);
            dp[i]=min(dp[i],dp[j-1]+mx);
        }
    }
    printf("%lld\n",dp[n]);
}

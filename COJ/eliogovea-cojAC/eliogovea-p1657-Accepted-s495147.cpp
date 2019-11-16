#include<cstdio>
#include<limits.h>
#include<algorithm>
using namespace std;

int c,n,ac[2501],dp[2501],x,m;

int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            ac[i]=ac[i-1]+x;
            x=INT_MAX;
            for(int j=1; j<=i; j++)
            x=min(x,ac[j]+dp[i-j]+2*m);
            dp[i]=x;
        }
        printf("%d\n",dp[n]-m);
        for(int i=1; i<=n; i++)ac[i]=dp[i]=0;
    }
    return 0;
}

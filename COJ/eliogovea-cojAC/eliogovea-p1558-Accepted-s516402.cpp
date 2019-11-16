#include<cstdio>

const int MOD = 1000000007;

int c,n;
long long dp[1000001];

int main()
{
    dp[0]=1;
    dp[1]=2;
    for(int i=2; i<=1000000; i++)
        dp[i]=(dp[i-1]+dp[i-2])%MOD;

    for(scanf("%d",&c);c--;)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}

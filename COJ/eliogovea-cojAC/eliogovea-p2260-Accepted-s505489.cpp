#include<cstdio>

const int MOD = 1000000007;
int t,n;
long long dp[1001];

int main()
{
    dp[0]=dp[1]=1;
    for(int i=2; i<=1000; i++)
        for(int j=0; j<i; j++)
            dp[i]=(dp[i]+(dp[j]*dp[i-1-j])%MOD)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}

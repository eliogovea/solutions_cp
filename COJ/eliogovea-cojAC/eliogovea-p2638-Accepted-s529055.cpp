#include<cstdio>

const int mod = 100999;

long dp[2001];
int c,n;

int main()
{
    dp[0]=1;
    for(int i=1; i<=2000; i++)
        for(int j=2000; j>=i; j--)
            dp[j]=(dp[j]+dp[j-i])%mod;

    for(scanf("%d",&c);c--;)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}

#include<cstdio>
#define MAXN 1000
#define mod 1000000007

int n,x=1,mx=1;
long long dp[MAXN+10][MAXN+10],ac[MAXN+10];

int main()
{
    ac[1]=1ll;
	for(scanf("%d",&n); n--;)
	{
		scanf("%d",&x);
		if(x>mx)
        {
            for(int i=mx+1; i<=x; i++)
			{
				dp[i][1]=dp[i][i]=1;
				ac[i]=1;
				for(int j=2; j<i; j++)
                    dp[i][j]=(dp[i-1][j-1]+(j*dp[i-1][j])%mod)%mod,
                    ac[i]=(ac[i]+dp[i][j])%mod;
                ac[i]=(ac[i]+1)%mod;
			}
			mx=x;
        }
        printf("%lld\n",ac[x]);
	}
}

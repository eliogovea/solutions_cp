#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 10000000;

int n,ac[501][501],dp[501][501],a[501];

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    for(int i=1; i<=n; i++)ac[i][i]=a[i];

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)ac[i][j]=ac[i][j-1]+a[j];

    for(int d=1; d<n; d++)
        for(int i=1; i<=n-d; i++)
        {
            int j=i+d;
            dp[i][j]=INF;
            for(int k=i; k<j; k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+max(ac[i][k],ac[k+1][j]));
        }

    printf("%d\n",dp[1][n]);
    return 0;
}

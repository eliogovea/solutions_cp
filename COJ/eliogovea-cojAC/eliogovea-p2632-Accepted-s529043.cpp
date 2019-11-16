#include<cstdio>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;

int a[110][110],
    dp[110][110],
    dp2[110][110],
    n,mx,mx2;

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            dp2[i][j]=sqr(a[i][j])+max(dp2[i-1][j-1],dp2[i-1][j]);
        }

    for(int i=1; i<=n; i++)
        if(mx<dp[n][i])
            mx=dp[n][i],
            mx2=dp2[n][i];

    printf("%d %d\n%c%c\n",mx2,mx,char((mx2)%26)+'a',char((mx)%26)+'a');
    return 0;
}

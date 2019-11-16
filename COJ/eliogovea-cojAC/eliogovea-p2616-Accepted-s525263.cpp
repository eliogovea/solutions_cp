#include<cstdio>
#include<algorithm>
using namespace std;

const int a[4]={1,3,5,6};
int dp[100001],n,c;

int main()
{
    for(int i=1; i<=100000; i++)
        dp[i]=1<<29;
    for(int i=0; i<4; i++)
        for(int j=a[i]; j<=100000; j++)
            dp[j]=min(dp[j],dp[j-a[i]]+1);
    scanf("%d",&c);
    for(int i=1; i<=c; i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,dp[n]);
    }
    return 0;
}

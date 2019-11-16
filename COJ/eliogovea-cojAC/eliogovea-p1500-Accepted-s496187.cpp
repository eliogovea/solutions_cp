#include<cstdio>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

vector<int>c;
int a[11],dp[101],dp1[101],n;

int main()
{
    for(int i=1; i<=10; i++)scanf("%d",&a[i]);
    scanf("%d",&n);

    for(int i=1; i<=n; i++)dp[i]=INT_MAX;

    for(int i=1; i<=10; i++)
        for(int j=i; j<=n; j++)
            if(dp[j]>=dp[j-i]+a[i])
            {
                dp[j]=dp[j-i]+a[i];
                dp1[j]=i;
            }

    int k=n;
    while(k)
    {
        c.push_back(dp1[k]);
        k-=dp1[k];
    }
    for(int i=c.size()-1; i>=0; i--)printf("%d %d\n",c[i],a[c[i]]);
    printf("%d\n",dp[n]);
    return 0;
}

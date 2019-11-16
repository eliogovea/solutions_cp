#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

int c,n,dp[1001];

int main()
{
    dp[1]=3;
    for(int i=2; i<1001; i++)
    {
        dp[i]=dp[i-1];
        for(int j=0; j<i; j++)
            dp[i]+=2*(gcd(i,j)==1);
    }
    scanf("%d",&c);
    for(int i=1; i<=c; i++)
    {
        scanf("%d",&n);
        printf("%d %d %d\n",i,n,dp[n]);
    }
    return 0;
}

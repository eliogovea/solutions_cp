#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

int gcd(int a, int b, int c)
{
    return gcd(a,gcd(b,c));
}

int c,n,dp[101];

int main()
{
    dp[1]=7;
    for(int i=2; i<101; i++)
    {
        dp[i]=dp[i-1];
        for(int j=0; j<=i; j++)
            for(int k=0; k<i; k++)
                dp[i]+=3*(gcd(i,j,k)==1);
    }

    for(scanf("%d",&c);c--;)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;

}
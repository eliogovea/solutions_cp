#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int t,n,a[200][200];

int main()
{
    scanf("%d",&t);
    for(int r=1; r<=t; r++)
    {
        scanf("%d",&n);

        for(int i=1; i<2*n; i++)
        for(int j=1; j<=min(i,2*n-i); j++)scanf("%d",&a[i][j]);

        for(int i=2; i<=n; i++)
        {
            a[i][1]+=a[i-1][1];
            a[i][i]+=a[i-1][i-1];
        }

        for(int i=3; i<=n; i++)
        for(int j=2; j<i; j++)a[i][j]+=max(a[i-1][j-1],a[i-1][j]);

        for(int i=n+1; i<2*n; i++)
        for(int j=1; j<=2*n-i; j++)a[i][j]+=max(a[i-1][j+1],a[i-1][j]);

        printf("Case %d: %d\n",r,a[2*n-1][1]);

        for(int i=1; i<2*n; i++)
        for(int j=1; j<=min(i,2*n-i); j++)a[i][j]=0;
    }
    return 0;
}

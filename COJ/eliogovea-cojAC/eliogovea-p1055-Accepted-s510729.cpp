#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll c[32][32],sum[32][32],p;
int n,l;

int main()
{
    for(int i=0; i<=31; i++)
        c[i][0]=c[i][i]=sum[i][0]=1;

    for(int i=2; i<=31; i++)
        for(int j=1; j<i; j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];

    for(int i=1; i<=31; i++)
        for(int j=1; j<=i; j++)
            sum[i][j]=sum[i][j-1]+c[i][j];

    while(scanf("%d%d%lld",&n,&l,&p)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            if(p>sum[n-i][min(l,n-i)])
            {
                printf("1");
                p-=sum[n-i][min(l,n-i)];
                l--;
            }
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}

#include<cstdio>

const int MOD = 1000000007;
int par[1001][1001],n,k,c;

int main()
{
    for(int i=1; i<=1000; i++)
    {
        par[1][i]=i;
        par[i][1]=1;
    }
    for(int i=2; i<=1000; i++)
        for(int j=2; j<=1000; j++)
            par[i][j]=(par[i-1][j]+par[i][j-1])%MOD;

    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",par[n][k]);
    }
    return 0;
}

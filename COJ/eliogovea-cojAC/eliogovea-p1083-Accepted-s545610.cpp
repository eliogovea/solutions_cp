#include<cstdio>
#include<algorithm>
#define MAXN 1000010
using namespace std;

int k,l,m;
bool dp[MAXN];

int main()
{
    scanf("%d%d%d",&k,&l,&m);

    for(int i=0; i<MAXN; i++)
    {
        if(i+1<MAXN)dp[i+1]|=!dp[i];
        if(i+l<MAXN)dp[i+l]|=!dp[i];
        if(i+k<MAXN)dp[i+k]|=!dp[i];
    }

    for(int i=1,x; i<=m; i++)
    {
        scanf("%d",&x);
        printf("%c",dp[x]?'A':'B');
    }
    printf("\n");
}
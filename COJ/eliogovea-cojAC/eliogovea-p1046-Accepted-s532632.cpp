#include<cstdio>

int dp[1000],c,a,b;

int main()
{
    for(int i=1; i<=1000; i++)
        dp[i]=(i*(i+1)*(i+2)+dp[i-1])%100;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",(dp[b]-dp[a-1]+100)%100);
    }
    return 0;
}

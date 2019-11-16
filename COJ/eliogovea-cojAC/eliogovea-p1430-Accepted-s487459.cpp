#include<cstdio>

const int MOD = 1000000009;

int n,dp[500][500],x,ans;
bool m[500][500];
char map[500][500];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        m[0][0]=1;
        dp[0][0]=1;
        for(int i=0; i<n; i++)
        {
            scanf("%s",&map[i]);
            for(int j=0; j<n; j++)
            {
                if(m[i][j])
                {
                    x=map[i][j]-'0';
                    if(i+x<n && x!=0)
                    {
                        dp[i+x][j]=(dp[i+x][j]+dp[i][j])%MOD;
                        m[i+x][j]=1;
                    }
                    if(j+x<n && x!=0)
                    {
                        dp[i][j+x]=(dp[i][j+x]+dp[i][j])%MOD;
                        m[i][j+x]=1;
                    }
                }
            ans=dp[n-1][n-1];
            dp[i][j]=m[i][j]=0;
            }
        }
    printf("%d\n",ans);
    }
return 0;
}

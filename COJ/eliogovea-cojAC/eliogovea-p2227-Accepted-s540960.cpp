#include<cstdio>
#include<algorithm>
using namespace std;

char m[15][15];
int dp[15][15],n,x,y,c,c1,c2;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s",m[i]);

    scanf("%d%d",&x,&y);

    for(int i=1; i<n; i++)
    {
        c=((m[i][0]-'0')-(m[i-1][0]-'0'))>0?
            (m[i][0]-'0')-(m[i-1][0]-'0'):0;
        dp[i][0]=dp[i-1][0]+c;
        c=((m[0][i]-'0')-(m[0][i-1]-'0'))>0?
            (m[0][i]-'0')-(m[0][i-1]-'0'):0;
        dp[0][i]=dp[0][i-1]+c;
    }
    for(int i=1; i<n; i++)
        for(int j=1; j<n; j++)
        {
            c1=((m[i][j]-'0')-(m[i][j-1]-'0'))>0?
                (m[i][j]-'0')-(m[i][j-1]-'0'):0;
            c2=((m[i][j]-'0')-(m[i-1][j]-'0'))>0?
                (m[i][j]-'0')-(m[i-1][j]-'0'):0;
            dp[i][j]=min(dp[i][j-1]+c1,dp[i-1][j]+c2);
        }


    printf("%d\n",dp[x-1][y-1]);
}

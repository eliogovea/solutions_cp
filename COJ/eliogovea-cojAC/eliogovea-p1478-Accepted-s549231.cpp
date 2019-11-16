#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1010
using namespace std;

char w1[MAXN],w2[MAXN];
int len1,len2;
int dp[MAXN][MAXN];

int main()
{
	scanf("%s%s",w1+1,w2+1);

	len1=strlen(w1+1);
	len2=strlen(w2+1);

	for(int i=0; i<=len1; i++)dp[i][0]=i;
	for(int i=0; i<=len2; i++)dp[0][i]=i;

	for(int i=1; i<=len1; i++)
		for(int j=1; j<=len2; j++)
			if(w1[i]==w2[j])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;

	printf("%d\n",dp[len1][len2]);
}

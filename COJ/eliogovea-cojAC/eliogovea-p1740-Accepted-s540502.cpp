#include<cstdio>
#include<cstring>
#define MAX 2010
char line[MAX];

int ini[MAX],fin[MAX];
bool dp[MAX][MAX];

long sol;

int main()
{
	scanf("%s",line+1);

	int len=strlen(line+1);

	for(int i=1; i<=len; i++)
		dp[i][i]=1;

	for(int i=1; i<len; i++)
		dp[i][i+1]=(line[i]==line[i+1]);

	for(int l=2; l<=len; l++)
		for(int i=1; i<=len; i++)
			dp[i][i+l]=(line[i]==line[i+l] && dp[i+1][i+l-1]);

	for(int i=1; i<=len; i++)
		for(int j=i; j<=len; j++)
            if(dp[i][j])
                ini[i]++,
                fin[j]++;

	for(int i=len-1; i; i--)
		ini[i]+=ini[i+1];

	for(int i=1; i<len; i++)
		sol+=fin[i]*ini[i+1];

	printf("%ld\n",sol);

}

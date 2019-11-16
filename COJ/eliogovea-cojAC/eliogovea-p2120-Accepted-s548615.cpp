#include<cstdio>
#define MAXN 5010

int dp[MAXN],a,b,digit;

bool is(int n)
{
	bool arr[10]={0,0,0,0,0,0,0,0,0,0};

	while(n)
	{
		digit=n%10;
		if(arr[digit])return 0;
		arr[digit]=1;
		n/=10;
	}
	return 1;
}



int main()
{
	for(int i=1; i<=5000; i++)
		dp[i]=dp[i-1]+is(i);

	while(scanf("%d%d",&a,&b)==2)
		printf("%d\n",dp[b]-dp[a-1]);
}

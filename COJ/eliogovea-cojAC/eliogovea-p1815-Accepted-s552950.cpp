#include<cstdio>
#define MAXN 1000001

int n,q,aux;
bool dp[MAXN];

int main()
{
	dp[0] = 1;

	scanf( "%d", &n );

	for( int i = 1; i <= n; i++ )
	{
		scanf( "%d", &aux );
		for( int j = MAXN - 1; j >= aux; j-- )
            dp[j] |= dp[j-aux];
	}

	for( scanf( "%d", &q ); q--; )
	{
		scanf( "%d", &aux );
		printf( "%s\n", dp[aux]?"YES":"NO" );
	}
}

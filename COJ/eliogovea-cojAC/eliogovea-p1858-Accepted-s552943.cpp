#include<cstdio>
#define MAXN 10020
typedef long long ll;

ll a,b,n,m;
ll dp[MAXN];

int main()
{
	scanf( "%lld%lld%lld%lld", &n, &a, &b, &m );

	dp[0] = 1ll;

	for( ll i = a; i <= b; i++ )
		for( ll j = i; j <= n; j++ )
			dp[j] = ( dp[j] + dp[j - i] ) % m;

	printf( "%lld\n", dp[n] );
}

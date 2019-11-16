#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10100;

int c,n,dp[MAXN],sol;
pair<int,int> a[MAXN];

int main()
{
	for ( scanf( "%d", &c ); c--; )
	{
		scanf( "%d", &n );

		for ( int i = 0, x, y, z; i < n; i++ )
		{
			scanf( "%d%d%d", &x, &y, &z );
			a[i] = make_pair( y, y + z );
		}
		sort( a, a + n );
		int sol = 0;
		for ( int i = 0; i < n; i++ )
		{
			dp[i] = 1;
			for ( int j = 0; j < i; j++ )
				if ( a[j].second <= a[i].first )
					dp[i] = max( dp[i], dp[j] + 1 );
			sol = max( sol, dp[i] );
		}
		printf( "%d\n", sol );
		if( c ) printf( "\n" );
	}
}

#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAXN = 1000;

ll a,b;
ll dp[MAXN+10];
bool mark[MAXN + 10][2];
vector<ll> v[2];

ll s( ll x )
{
	if( x == 0ll ) return 0ll;

	if( x <= MAXN )
	{
		if( dp[x] ) return dp[x];
		int r = x % 10;
		return dp[x] = s( x / 10 ) + r * r;
	}
	int r = x % 10;
	return s( x / 10 ) + r * r;
}

void f( int x, int t )
{
	if( x > MAXN )
	{
		v[t].push_back( x );
		x = s( x );
	}
	while( !mark[x][t] )
	{
		mark[x][t] = 1;
		v[t].push_back( x );
		x = s( x );
	}

}

int main()
{
	while( scanf( "%lld%lld", &a, &b ) )
	{
		if( a == 0 && b == 0 ) break;

		v[0].clear();
		v[1].clear();
		for( int i = 0; i <= MAXN; i++ )
			mark[i][0] = mark[i][1] = 0;

		f( a, 0 );
		f( b, 1 );

		ll sol = 10000ll;

		for( int i = 0; i < v[0].size(); i++ )
			for( int j = 0; j < v[1].size(); j++ )
				if( v[0][i] == v[1][j] ) sol = min( sol, ll(i + j + 2) );
        printf( "%lld %lld ", a, b );
		if( sol == 10000 ) printf( "0\n" );
		else printf( "%lld\n", sol );

	}
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000000;

ll n, a, b;
bool criba[MAXN + 10];
vector<ll> p, ap;

int main()
{
	for ( ll i = 2; i * i <= MAXN; i++ )
		if ( !criba[i] )
			for ( ll j = i * i; j <= MAXN; j += i )
				criba[j] = 1;
	for ( ll i = 2; i <= MAXN; i++ )
		if ( !criba[i] ) p.push_back( (ll)i );
		
	for ( ll i = 0; i < p.size(); i++ )
	{
		ll x = p[i] * p[i];
		while ( x < (ll)1e12 )
		{
			ap.push_back( x );
			x *= p[i];
		}
	}

	sort( ap.begin(), ap.end() );

	scanf( "%lld", &n );
	for ( ll i = 1; i <= n; i++ )
	{
		scanf( "%lld%lld", &a, &b );
		ll ini = lower_bound( ap.begin(), ap.end(), a ) - ap.begin();
		ll fin = upper_bound( ap.begin(), ap.end(), b ) - ap.begin();
		printf( "%lld\n", fin - ini );
	}
}

#include <cstdio>
using namespace std;

const int MAXN = 15;
typedef long long ll;

ll c, n, p5[MAXN];

int main()
{
	p5[0] = 1;
	for ( int i = 1; i < MAXN; i++ ) p5[i] = p5[i - 1] * 5ll;
	for ( scanf( "%lld", &c ); c--; )
	{
		scanf( "%lld", &n );
		ll sol = 0ll;
		for( int i = 0; i < MAXN; i++ )
			if( n & ( 1 << i ) ) sol += p5[i + 1];
		printf( "%lld\n", sol );
	}
}

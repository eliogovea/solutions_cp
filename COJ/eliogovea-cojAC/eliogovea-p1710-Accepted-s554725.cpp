#include<cstdio>
#include<vector>
#define MAXN 100010
using namespace std;

int cas,x,sol;
bool sieve[MAXN];
vector<int> P;
vector<int>::iterator it;

int main()
{
	for( int i = 2; i * i < MAXN; i++ )
		if( !sieve[i] )
			for( int j = i * i; j < MAXN; j += i )
				sieve[j] = 1;
	for( int i = 2; i < MAXN; i++ )
		if( !sieve[i] )
			P.push_back( i );

	for( scanf( "%d", &cas ); cas--; )
	{
		scanf( "%d", &x );

		sol = 0;

		for( it = P.begin(); it != P.end(); it++ )
			if( x % *it == 0 )
			{
				sol++;
				while( x % *it == 0 )
					x/=*it;
			}

		if( x > 1 )sol++;

		printf( "%d\n", sol );
	}
}

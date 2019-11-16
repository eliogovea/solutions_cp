#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;

int n,a[MAXN+10];

int main()
{
	while( scanf( "%d", &n ) == 1 )
	{
		for( int i = 1, x; i <= n; i++ )
		{
			scanf( "%d", &x );
			a[i] = a[i - 1] + x;
		}
		if( a[n] % 3 )printf( "0\n" );
		else
		{
			int s = 0;
			for( int i = 0; i < n; i++ )
				if( binary_search( a, a + n + 1, ( a[i] + a[n] / 3 ) % a[n] )
					&& binary_search( a, a + n + 1, ( a[i] + 2 * a[n] / 3 ) % a[n] ) )
					s++;
			printf( "%d\n", s/3 );
		}
	}
}

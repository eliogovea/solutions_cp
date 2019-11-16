#include<cstdio>
#include<algorithm>
using namespace std;

int cas,n,mx,mn,x;

int main()
{
	for( scanf( "%d", &cas ); cas--; )
	{
		mx = -1;
		mn = 100;

		for( scanf( "%d", &n ); n--; )
		{
			scanf( "%d", &x );
			mx = max( mx, x );
			mn = min( mn, x );
		}

		printf( "%d\n", ( mx - mn ) * 2 );
	}
}

#include<cstdio>
#define MAXN 1000010

int cas,n,m,x,ac,arr[MAXN],sol;

int main()
{

	for( scanf( "%d", &cas ); cas--; )
	{
		scanf( "%d%d", &m, &n );

		ac = sol = 0;

		for( int i = 1; i <= n; i++ )
		{
			scanf( "%d", &x );
			ac = ( ac + x ) % m;
			if( ac == 0 )sol++;
			sol += arr[ac]++;
		}

		printf( "%d\n", sol );

		if( cas )
            for( int j = 0; j < m; j++ )
                arr[j] = 0;
	}
}

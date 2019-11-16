#include<cstdio>
#define MAXN 55

int n,mx,male[MAXN],female[MAXN];

int main()
{
	female[0] = 1;

	while( scanf( "%d", &n ) && n != -1 )
	{
		if( n > mx )
		{
			for( int i = mx + 1; i <= n; i++ )
			{
				male[i] = female[i-1] + male[i-1];
				female[i] = male[i-1] + 1;
			}
			mx = n;
		}
		printf( "%d %d\n", male[n], male[n] + female[n] );
	}
}

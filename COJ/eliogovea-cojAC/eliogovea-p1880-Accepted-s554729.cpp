#include<cstdio>

int cas,n,s[2];
char line[55];

inline void sum( int x )
{
	for( int i = 1; i <= n; i++ )
	{
		scanf( "%s", line + 1 );
		for( char *p = line + 1; *p; p++ )
			s[x] += *p - '0';
	}
}

int main()
{
	for( scanf( "%d", &cas ); cas--; )
	{
		scanf( "%d", &n );

		s[0] = 0; sum(0);
		s[1] = 0; sum(1);

		printf( "%s\n", ( s[0] == s[1] )?"YES":"NO" );
	}
}

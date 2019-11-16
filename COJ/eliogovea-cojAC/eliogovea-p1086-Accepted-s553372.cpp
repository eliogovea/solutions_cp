#include<cstdio>
#define MAXN 4567891

int x,s[MAXN];

int main()
{
	for( int i = 2; i < MAXN; i++ )
        s[i] = 1;

	for( int i = 2; i * i < MAXN; i++ )
		if( s[i] )
            for( int j = i * i; j < MAXN; j += i )
                s[j] = 0;

	for( int i = 2; i < MAXN; i++ )
		s[i] += s[i-1];

	for( int i = 0; i < 10; i++ )
	{
		scanf( "%d", &x );
		printf( "%d\n", s[x] );
	}
}

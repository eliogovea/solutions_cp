#include<cstdio>

const int corr[] = { 1, 1, 2, 2, 2, 8 };

int n,x;

int main()
{
	for( scanf( "%d", &n ); n--; )
	{
		for( int i = 0; i < 6; i++ )
		{
			scanf( "%d", &x );
			printf( "%d", corr[i] - x );
			if( i < 5 )printf( " " );
			else printf( "\n" );
		}
	}
}

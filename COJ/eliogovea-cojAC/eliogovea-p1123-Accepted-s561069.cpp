#include<cstdio>
#include<algorithm>
#define MAXN 1500
using namespace std;

int x,a[MAXN+10];

int main()
{
	a[1] = 1;
	for( int i = 2; i <= MAXN; i++ )
	{
	    int next = 1 << 30;
		for( int j = i - 1; j; j-- )
		{
			if( 2 * a[j] > a[i - 1] )next = min( next, 2 * a[j] );
			if( 3 * a[j] > a[i - 1] )next = min( next, 3 * a[j] );
			if( 5 * a[j] > a[i - 1] )next = min( next, 5 * a[j] );
		}
		a[i] = next;
	}

	while( scanf( "%d", &x ) && x )
		printf( "%d\n", a[x] );
}

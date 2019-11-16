#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 20;
const int MAXE = 100;

int n,m,E,a,b,ady[MAXE],next[MAXE],last[MAXN];

bool mark[MAXN];
int sol = 1000;

void f( int c, int cant, int mx )
{
	if( mx > sol ) return;

	if( c == 0 )
	{
		sol = min( sol, mx );
		//printf( "\n" );
		return;
	}
	for( int i = 0; i < n; i++ )
		if( !mark[i] )
		{
		    //printf( "%d ", i );
			mark[i] = 1;
			int aux = cant;
			for( int e = last[i]; e != -1; e = next[e] )
				if( mark[ady[e]] ) aux--;
				else aux++;
			f( c - 1, aux, max( mx, aux ) );
			mark[i] = 0;

		}
}

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n; i++ ) last[i] = -1;
	for( int i = 0; i < m; i++ )
	{
		scanf( "%d%d", &a, &b );
		a--;
		b--;
		ady[E] = b; next[E] = last[a]; last[a] = E++;
		ady[E] = a; next[E] = last[b]; last[b] = E++;
	}

	f( n, 0, 0 );

	printf( "%d\n", sol );
}

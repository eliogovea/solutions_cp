#include<cstdio>
#define MAXN 1010
#define MAXE 20010
using namespace std;

int N,M,E,source,sink;
int ady[MAXE],cap[MAXE],flow[MAXE],next[MAXE];
int last[MAXN],used[MAXN],id;

inline void addEdge( int a, int b )
{
	ady[E] = b; cap[E] = 1; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; next[E] = last[b]; last[b] = E++;
}

int dfs( int u )
{
	if( u == sink )
		return 1;

	if( used[u] == id )
		return 0;

	used[u] = id;

	for( int e = last[u]; e != -1; e = next[e] )
		if( cap[e] > flow[e] )
		{
			int res = dfs( ady[e] );
			if( res )
			{
				flow[e] += 1;
				flow[e^1] -= 1;
				return 1;
			}
		}
	return 0;
}

int maxflow()
{
	int f, tot = 0;
	while( true )
	{
	    id++;
		f = dfs( source );
		if( f == 0 )break;
		tot += f;
	}
	return tot;
}

int main()
{
	scanf( "%d%d", &N, &M );

	source = 0;
	sink = 2 * N + 1;
	for( int i = 0; i <= sink; i++ )
		last[i] = -1;

	for( int i = 1; i <= N; i++ )
	{
		addEdge( source, i );
		addEdge( N + i, sink );
	}

	for( int i = 1, x, y; i <= M; i++ )
	{
		scanf( "%d%d", &x, &y );
		addEdge( x, N + y );
	}

	printf( "%d\n", maxflow() );
}

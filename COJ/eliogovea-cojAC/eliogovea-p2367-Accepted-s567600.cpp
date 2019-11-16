#include<cstdio>
#include<algorithm>
using namespace std;

struct point {
	int x, y;
	point(){}
	point( int a, int b ) {
        x = a;
        y = b;
	}
};

const int MAXN = 40;

int cas,n,ii,jj,kk,mx;
point p[MAXN];

double ab( double x ) {
	if( x < 0 ) return -1.0 * x;
	return x;
}

/*int dist2( point a, point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

int dist3( point a, point b, point c ) {
    return dist2( a, b ) + dist2( b, c ) + dist2( a, c );
}*/

double area( point a, point b, point c ) {
	return ab( ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x ) );
}

int main() {
	for( scanf( "%d", &cas ); cas--; ) {
		scanf( "%d", &n );
		mx = 0;
		for( int i = 0; i < n; i++ ) scanf( "%d%d", &p[i].x, &p[i].y );

		for( int i = 0; i < n; i++ )
			for( int j = i + 1; j < n; j++ )
				for( int k = j + 1; k < n; k++ ) {
                    //printf( "%d %d %d %lf\n", i, j, k, area( p[i], p[j], p[k] ) );
					if( area( p[i], p[j], p[k] ) > mx ) {
						mx = area( p[i], p[j], p[k] );
						ii = i;
						jj = j;
						kk = k;
					}
					else if( area( p[i], p[j], p[k] ) == mx ) {
						if( i < ii || ( i == ii && j < jj ) || ( i == ii && j == jj && k < kk ) ) {
							ii = i;
							jj = j;
							kk = k;
						}
					}
				}
		printf( "%d %d %d\n", ii, jj, kk );
	}
}

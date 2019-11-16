#include<iostream>
using namespace std;

typedef long long ll;

int signo( ll x ) {
    if( x < 0ll ) return -1;
    else if( x == 0ll ) return 0;
    return 1;
}

struct point {
	ll x, y;
	point(){}
	point( ll a, ll b ) { x = a; y = b; }
};

ll cross( point a, point b, point c ) {
	return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}

point a,b,c,p;

int main() {

	cin >> a.x >> a.y
		>> b.x >> b.y
		>> c.x >> c.y
		>> p.x >> p.y;

	int v1 = signo( cross( p, a, b ) );
	int v2 = signo( cross( p, b, c ) );
	int v3 = signo( cross( p, c, a ) );

    if( v1 == v2 && v2 == v3 ) cout << 1 << endl;
    else if( v1 == 0
            && p.x >= min( a.x, b.x )
            && p.x <= max( a.x, b.x )
            && p.y >= min( a.y, b.y )
            && p.y <= max( a.y, b.y ) ) cout << '1' << endl;
    else if( v2 == 0
            && p.x >= min( b.x, c.x )
            && p.x <= max( b.x, c.x )
            && p.y >= min( b.y, c.y )
            && p.y <= max( b.y, c.y ) ) cout << '1' << endl;
    else if( v3 == 0
            && p.x >= min( c.x, a.x )
            && p.x <= max( c.x, a.x )
            && p.y >= min( c.y, a.y )
            && p.y <= max( c.y, a.y ) ) cout << '1' << endl;
    else cout << '0' << endl;
}

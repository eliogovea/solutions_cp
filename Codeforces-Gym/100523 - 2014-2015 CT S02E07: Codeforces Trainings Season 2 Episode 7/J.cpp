// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523J

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for(int i = 0; i < (int)(n); ++i)
#define ffor(i, n) for(int i = 1; i <= (int)(n); ++i)
#define revforr(n , i) for(int i = (int)(n)-1; i >= 0; i--)

#define kasign(a,b) a = b

#define keqq( a , b ) (a == b)
#define kmineqq( a , b ) ( a <= b )
#define kmaxeqq( a , b ) ( a >= b )

#define kmm(a) a++

#define kadd(a,b) a+=b
#define krest(a,b) a-=b
#define kmas(a,b) (a+b)

#define kxorr( a , b ) (a ^ b)

#define kfill( a , n , v ) fill( a , a + n , v )
#define kmod( a , b ) ( a % b )

typedef long long ll;
const int MAXN = 3000005;

int n;
int E;
int ady[MAXN], next[MAXN], last[MAXN];

int k2;

int cnt[MAXN];

void dfs1( int u, int p ){
    kasign( cnt[u] , 1 );
    for( int e( last[u] ); e ; kasign( e, next[e] ) ){
        int v( ady[e] );

        if( keqq( p , v ) ){
            continue;
        }

        dfs1( v , u );
        kadd( cnt[u] , cnt[v] );
    }
}

bool ok( int u, int p, int rest ){
    rest--;
    if( rest < 0 ){
        kasign( rest , k2 - 1 );
    }

    for( int e( last[u] ); e ; kasign( e, next[e] ) ){
        int v( ady[e] );
        if( keqq( v , p ) ){
            continue;
        }

        if( !ok( v , u , kmod( cnt[v] , k2 ) ) ){
            return false;
        }

        krest( rest , kmod( cnt[v] , k2 ) );

        if( rest < 0 ){
            return false;
        }
    }

    return ( !rest );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;

    kasign( E , 1 );

    for( int u( 2 ); !(u > n); kmm(u) ){
        int p; cin >> p;

        kasign( ady[E] , u );
        kasign( next[E] , last[p] );
        kasign( last[p] , E );
        kmm(E);
        //g[p].push_back( u );
    }

    dfs1( 1 , -1 );
    cout << "1";

    for( int k( 2 ); !( k > n ); kmm(k) ){
        if( !kmod( n , k ) ){
            kasign( k2 , n / k );
            if( ok( 1 , -1 , 0 ) ){
                cout << ' ' << k;
            }
        }
    }
    cout << "\n";
}

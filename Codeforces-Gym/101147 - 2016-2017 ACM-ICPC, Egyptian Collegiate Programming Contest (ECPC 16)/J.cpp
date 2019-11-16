// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147J

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> par;

struct data{
    ll v;
    int ord, nod, kk;
    data(){}
    data( ll vv, int ordd, int nodd, int kkk ){
        v = vv;
        ord = ordd;
        nod = nodd;
        kk = kkk;
    }

    bool operator < ( const data &o ) const {
        if( v != o.v ){
            return v < o.v;
        }

        return ord < o.ord;
    }
};

const int MAXN = 3000100;
int n;

int BIT[MAXN];
void upd_bit( int i, int v ){
    while( i <= n*4 ){
        BIT[i] += v;
        i += ( i & -i );
    }
}

int get_bit( int i ){
    int ret = 0;
    while( i > 0 ){
        ret += BIT[i];
        i -= ( i & -i );
    }
    return ret;
}

int ord[MAXN];
int sz;

ll d[MAXN];
ll x[MAXN];

vector<par> g[MAXN];
data a[MAXN];

void dfs( int u, int p ){
    a[sz] = data( d[u] - x[u] , sz , u , 0 );
    sz++;
    a[sz] = data( d[u] , sz , u , -1 );
    sz++;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i].first;
        ll w = g[u][i].second;

        if( v != p ){
            d[v] = d[u] + w;
            dfs( v , u );
        }
    }

    a[sz] = data( d[u] , sz , u , 1 );
    sz++;
}

int sol[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen( "dat.txt", "r", stdin );
    freopen( "car.in", "r", stdin );

    int tc; cin >> tc;

    while( tc-- ){
        cin >> n;

        //clear
        fill( BIT , BIT + n * 4 + 1 , 0 );
        fill( sol , sol + n * 4 + 1 , 0 );

        for( int i = 1; i <= n; i++ ){
            cin >> x[i];
            g[i].clear();
        }

        for( int i = 1; i < n; i++ ){
            int u, v; cin >> u >> v;
            ll w; cin >> w;
            g[u].push_back( par( v , w ) );
            g[v].push_back( par( u , w ) );
        }

        sz = 1;
        d[1] = 0;
        dfs( 1 , -1 );

        sort( a + 1 , a + sz );

        for( int i = 1; i < sz; i++ ){
            int u = a[i].nod;
            int ord = a[i].ord;
            int kk = a[i].kk;

            if( kk == 0 ){
                upd_bit( ord , 1 );
                continue;
            }
            sol[u] += get_bit( ord ) * kk;
        }

        for( int i = 1; i <= n; i++ ){
            cout << sol[i] << " \n"[i==n];
        }
    }
}

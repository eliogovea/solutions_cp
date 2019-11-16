// 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630L

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
const int MAXLG = 25;
vector<int> g[MAXN];
vector<int> tson[MAXN];
int p[MAXN][MAXLG];
int lev[MAXN];
int tin[MAXN];

void dfs( int u, int &t ){
    tin[u] = ++t;
    for( int i = 0; i < g[u].size(); i++ ){
        if( g[u][i] == p[u][0] ){
            swap( g[u][i] , g[u][ g[u].size()-1 ] );
            break;
        }
    }
    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( v != p[u][0] ){
            p[v][0] = u;
            lev[v] = lev[u] + 1;
            dfs(v,t);
        }
    }

    for( auto v : g[u] ){
        if( v != p[u][0] ){
            tson[u].push_back( tin[v] );
        }
    }
}

int LCA( int u, int v ){
    if( lev[u] < lev[v] ) swap( u , v );

    for( int i = MAXLG-1; i >= 0; i-- ){
        if( lev[ p[u][i] ] >= lev[v] ){
            u = p[u][i];
        }
    }

    if( u == v ) return u;
    for( int i = MAXLG-1; i >=0 ; i-- ){
        if( p[u][i] != p[v][i] ){
            u = p[u][i];
            v = p[v][i];
        }
    }

    return p[u][0];
}

int dist( int u, int v ){
    int lca = LCA( u , v );
    return lev[u] + lev[v] - 2*lev[lca];
}

int go( int u, int v ){
    if( u == v ) return u;
    int lca = LCA( u , v );

    if( lca != u ){
        return p[u][0];
    }

    int p = upper_bound( tson[u].begin() , tson[u].end() , tin[v] ) - tson[u].begin();
    p--;

    return g[u][p];
}

typedef pair<int,int> par;
typedef pair<int,par> kk;

int mk[MAXN];
int parent[MAXN];
int a[MAXN], b[MAXN];

int ady( int e, int u ){
    return (a[e] == u ? b[e] : a[e]);
}

bool ext( int e, int u ){
    return (a[e] == u || b[e] == u);
}

bool contiene( int E, int e ){
    return dist( a[E] , a[e] ) + dist( a[e] , b[e] ) + dist( b[e] , b[E] ) == dist( a[E] , b[E] ) ||
           dist( b[E] , a[e] ) + dist( a[e] , b[e] ) + dist( b[e] , a[E] ) == dist( a[E] , b[E] );
}

bool ok( int &u, int &v, int i ){
    if( mk[u] ){
        if( !ext( mk[u] , u ) ){
            return false;
        }
        if( parent[ mk[u] ] && parent[ mk[u] ] != i+1 && parent[ mk[u] ] != mk[u] ){
            return false;
        }
        if( !contiene( i+1 , mk[u] ) ){
            return false;
        }
        parent[ mk[u] ] = i+1;
        u = go( ady( mk[u] , u ) , v );
    }
    else{
        mk[u] = i+1;
        parent[ mk[u] ] = i+1;
        u = go( u , v );
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, f; cin >> n >> f;

    for( int i = 0; i+1 < n; i++ ){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lev[1] = 1;
    int t = 0;
    dfs(1,t);

    for( int i = 1; i < MAXLG; i++ ){
        for( int u = 1; u <= n; u++ ){
            p[u][i] = p[ p[u][i-1] ][i-1];
        }
    }

    vector<kk> x;
    for( int i = 0; i < f; i++ ){
        int u, v; cin >> u >> v;
        x.push_back( kk( dist(u,v) , par( u , v ) ) );
    }

    sort( x.begin() , x.end() );

    for( int i = 0; i < x.size(); i++ ){
        int u = x[i].second.first;
        int v = x[i].second.second;
        int len = x[i].first;

        a[i+1] = u;
        b[i+1] = v;

        while( u != v ){
            if( !ok( u , v , i ) ){
                cout << "No\n";
                return 0;
            }
        }

        if( !ok( u , v , i ) ){
            cout << "No\n";
            return 0;
        }

        mk[ a[i+1] ] = mk[ b[i+1] ] = i+1;
    }

    cout << "Yes\n";
}

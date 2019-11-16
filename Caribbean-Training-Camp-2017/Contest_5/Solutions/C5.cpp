#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> par;

const int MAXN = 100100;

int p[MAXN];
ll w[MAXN];

void splay( int u, int son = 0 ){
    if( p[u] ){
        splay( p[u] , u );
    }

    p[u] = son;
    w[u] = w[son];
}

typedef long long ll;

ll sol;

int mk[MAXN];
int mark;

int getlca( int u, int v ){
    mk[u] = ++mark;
    int x = u;

    while( p[x] ){
        x = p[x];
        mk[x] = mark;
    }

    x = v;
    if( mk[x] == mark ){
        return x;
    }

    while( p[x] ){
        x = p[x];
        if( mk[x] == mark ){
            return x;
        }
    }

    return 0;
}

void add( int u, int v, ll c ){
    if( u == v ){
        return;
    }

    int lca = getlca( u , v );

    if( !lca ){
        sol += c;
        splay(v);
        p[v] = u;
        w[v] = c;
        return;
    }

    int max_wv = 0;
    int x = u;
    while( x != lca ){
        if( w[max_wv] < w[x] ){
            max_wv = x;
        }

        x = p[x];
    }

    x = v;
    while( x != lca ){
        if( w[max_wv] < w[x] ){
            max_wv = x;
        }

        x = p[x];
    }

    if( w[max_wv] < c ){
        return;
    }

    sol += ( c - w[max_wv] );
    p[max_wv] = 0;
    w[max_wv] = 0;

    splay(v);

    p[v] = u;
    w[v] = c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 1; i <= m; i++ ){
        int u, v; ll c; cin >> u >> v >> c;
        add( u , v , c );

        cout << sol << '\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];

int d[3][MAXN];
int x;
void dfs( int u, int p, int *d ){
    d[u] = d[p] + 1;
    if( d[x] < d[u] ){
        x = u;
    }

    for( auto v : g[u] ){
        if( v != p ){
            dfs( v , u , d );
        }
    }
}

int a, b;
void solve( int n ){
    x = 1;
    dfs( 1 , 0 , d[0] );
    a = x;
    dfs( a , 0 , d[1] );
    b = x;
    dfs( b , 0 , d[2] );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    for( int i = 1; i < n; i++ ){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(n);

   // cerr << "a = " << a << "  b = " << b << '\n';

    for( int u = 1; u <= n; u++ ){
        cout << max( d[1][u] , d[2][u] ) - 1 << " \n"[u == n];
    }
}

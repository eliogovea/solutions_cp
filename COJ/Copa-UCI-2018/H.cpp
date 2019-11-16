#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

vector<int> g[MAXN];

int sol[MAXN];

void solve( int u, int mk ){
    sol[u] = mk;
    for( auto v : g[u] ){
        if( !sol[v] ){
            solve( v , sol[u] % 2 + 1 );
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    while( m-- ){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for( int u = 1; u <= n; u++ ){
        if( g[u].size() == 0 ){
            cout << "Impossible\n";
            return 0;
        }
        if( !sol[u] )
            solve( u , 1 );
    }

    cout << "Possible\n";
    for( int u = 1; u <= n; u++ ){
        cout << sol[u] << '\n';
    }
}


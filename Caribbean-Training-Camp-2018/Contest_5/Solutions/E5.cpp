#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];
int gr[MAXN];

bool mk[MAXN];

void solve( int u ){ if( mk[u] ) return;
    mk[u] = true;
    set<int> s;
    for( auto v : g[u] ){
        solve( v );
        s.insert( gr[v] );
    }

    while( s.find( gr[u] ) != s.end() ){
        gr[u]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 0; i < m; i++ ){
        int u,v ; cin >> u >> v;
        g[u].push_back(v);
    }

    for( int u = 1; u <= n; u++ ){
        solve(u);
        cout << gr[u] << "\n";
    }
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int go[MAXN], from[MAXN];
vector<int> g[MAXN];

bool mk[MAXN];
bool dfs( int u ){
    if( mk[u] )return false;
    mk[u] = true;
    for( auto v : g[u] ){
        if( !from[v] || dfs( from[v] ) ){
            go[u] = v;
            from[v] = u;
            return true;
        }
    }
    return false;
}

bool loose[MAXN];
void solve1( int u ){
    loose[u] = true;
    for( auto v : g[u] ){
        if( v != go[u] && !loose[ from[v] ] ){
            solve1( from[v] );
        }
    }
}

void solve2( int u ){
    //cerr << "solve2  u = " << u << '\n';
    loose[u] = true;
    for( auto v : g[u] ){
        if( v != from[u] && !loose[ go[v] ] ){
            //cerr << " --->  v = " << v << "  from[v] = " << go[v] << '\n';
            solve2( go[v] );
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n1, n2, m; cin >> n1 >> n2 >> m;

    for( int i = 0; i < m; i++ ){
        int u, v; cin >> u >> v; v += n1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for( int u = 1; u <= n1; u++ ){
        fill( mk , mk + n1 + 1 , false );
        dfs(u);
    }

    for( int u = 1; u <= n1; u++ ){
        if( !go[u] ){
            solve1(u);
        }
    }
    for( int u = n1+1; u <= n1 + n2; u++ ){
        if( !from[u] ){
            solve2(u);
        }
    }

    for( int u = 1; u <= n1 + n2; u++ ){
        if( u == n1 + 1 ){
            cout << '\n';
        }
        cout << ( loose[u] ? 'P' : 'N' );
    }
    cout << '\n';

    //cout << "matching:\n";
    /*
    for( int u = 1; u <= n1; u++ ){
        for( int v = n1+1; v <= n1 + n2; v++ ){
            if( go[u] == v ){
                cout << u << ' ' << v << '\n';
            }
        }
    }
    */
}

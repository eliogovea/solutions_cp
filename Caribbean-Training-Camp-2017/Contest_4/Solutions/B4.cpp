#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

int from[MAXN];
bool mk[MAXN];

vector<int> g[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !from[v] || dfs( from[v] ) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

typedef pair<int,int> par;

bool ok[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 1; i <= n; i++ ){
        int v;
        while( cin >> v, v ){
            g[i].push_back(v);
        }
    }

    int mxf = 0;

    for( int i = 1; i <= n; i++ ){
        fill( mk , mk + n + 1 , false );
        if( dfs(i) ){
            mxf++;
        }
    }

    //cerr << "---->\n";

    //cerr << "m = " << m << '\n';

    set<par> sol;
    for( int i = 1; i <= m; i++ ){
        //cerr << "i = " << i << "  from[i] = " << from[i] << '\n';
        if( from[i] ){
            sol.insert( par( from[i] , i ) );
            ok[ from[i] ] = true;
        }
    }

    //cerr << "<----n";

    for( int u = 1; u <= n; u++ ){
        for( int j = 0; j < g[u].size(); j++ ){
            int v = g[u][j];
            if( !ok[u] || !from[v] ){
                ok[u] = true;
                from[v] = u;
                sol.insert( par( u , v ) );
            }
        }
    }

    set<par>::iterator it = sol.begin();

    cout << sol.size() << '\n';

    while( it != sol.end() ){
        cout << (*it).first << ' ' << (*it).second << '\n';
        it++;
    }
}

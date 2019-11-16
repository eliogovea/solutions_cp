// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30000;

vector<int> g[MAXN];
vector<int> rg[MAXN];

int pos;
int order[MAXN];

bool mk[MAXN];

void dfs( int u ){
    if( mk[u] ){
        return;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        dfs(v);
    }

    order[--pos] = u;
}

int cnt[MAXN];
int SCC[MAXN];
int sz_scc;

void go( int u ){
    SCC[u] = sz_scc;
    cnt[sz_scc]++;
    mk[u] = true;

    for( int i = 0; i < rg[u].size(); i++ ){
        int v = rg[u][i];
        if( !mk[v] ){
            go( v );
        }
    }
}

const int MAXV = 1010;

vector<int> G[MAXV];
int ok[MAXV][MAXV];
int is_ok( int u, int v ){
    if( ok[u][v] ){
        return ok[u][v];
    }

    if( u == v ){
        return (ok[u][v] = 1);
    }

    ok[u][v] = -1;
    for( int i = 0; i < G[u].size(); i++ ){
        int x = G[u][i];
        if( is_ok( x , v ) == 1 ){
            ok[u][v] = 1;
            break;
        }
    }

    return ok[u][v];
}

int solve( int u, int v ){
    if( is_ok(u,v) == -1 ){
        swap( u , v );
    }

    int sol = 0;
    for( int i = 1; i <= sz_scc; i++ ){
        if( is_ok( u , i ) == 1 && is_ok( i , v ) == 1 ){
            sol += cnt[i];
        }
    }

    return sol;
}

typedef pair<int,int> par;
par arcs[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	vector<int> sol;

	int n, m; cin >> n >> m;
	for( int i = 0; i < m; i++ ){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);

        sol.push_back(i+1);
        arcs[i+1] = par( u , v );
	}

    pos = n+1;
    for( int i = 1; i <= n; i++ ){
        dfs(i);
    }

    fill( mk , mk + n + 1 , false );

    sz_scc = 0;
    for( int i = 1; i <= n; i++ ){
        if( !mk[ order[i] ] ){
            sz_scc++;
            go( order[i] );
        }
    }

    //cerr << "sz_scc = " << sz_scc << '\n';

    for( int i = 1; i <= m; i++ ){
        int u = arcs[i].first;
        int v = arcs[i].second;

        //cerr << "--->  " << u << ' ' << v << '\n';

        u = SCC[u];
        v = SCC[v];

        if( u != v ){
            G[u].push_back(v);
            //cerr << "---->   " << u << ' ' << v << '\n';
        }
    }

    //cerr << "is_ok = " << is_ok( 3 , 5 ) << '\n';

    int solw = 0;
    for( int i = 1; i <= sz_scc; i++ ){
        solw = max( solw , cnt[i] );
    }

    int WW = solw;

    for( int i = 1; i <= m; i++ ){
        int u = arcs[i].first;
        int v = arcs[i].second;

        u = SCC[u];
        v = SCC[v];

        int tmp = 0;
        if( u != v && solw <= (tmp = solve( u , v )) ){
            if( tmp == WW ){
                continue;
            }

            if( solw < tmp ){
                sol.clear();
            }

            sol.push_back(i);
            solw = tmp;
        }
    }

    cout << solw << '\n';
    cout << sol.size() << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i] << " \n"[i+1==sol.size()];
    }
}

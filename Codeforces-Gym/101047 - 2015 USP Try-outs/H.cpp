// 2015 USP Try-outs
// 101047H

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;

int col[MAXN];
vector<int> g[MAXN];

void dfs( int u ){
    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];

        if( col[v] != -1 ){
            continue;
        }

        col[v] = (col[u] + 1) % 2;

        dfs(v);
    }
}

bool mk[MAXN];
int from[MAXN];

bool kuhn( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !from[v] || kuhn( from[v] ) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);

	//freopen("dat.txt", "r", stdin);

	int tc; cin >> tc;

	while( tc-- ){
        int n, m; cin >> n >> m;
        for( int i = 1; i <= n; i++ ){
            col[i] = -1;
            g[i].clear();
            from[i] = 0;
        }

        for( int i = 0; i < m; i++ ){
            int u, v; cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        col[1] = 1;
        dfs(1);

        int mxf = 0;
        int one = 0;
        for( int u = 1; u <= n; u++ ){
            if( col[u] ){
                one++;
                fill( mk , mk + 1 + n , false );
                if( kuhn( u ) ){
                    mxf++;
                }
            }
        }

        n = n - one;
        m = one;

        cout << (n+m) - mxf << '\n';
	}
}

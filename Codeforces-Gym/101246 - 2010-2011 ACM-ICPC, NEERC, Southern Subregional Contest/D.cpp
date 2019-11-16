// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246D

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4000;

vector<int> g[MAXN];
int lev[MAXN];
bool sol[MAXN];

int cola[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n,m; cin >> n >> m;

	for( int i = 1; i <= m; i++ ){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
	}

	int enq = 0, deq = 0;

	cola[enq++] = 1;
	lev[1] = 1;

	while( enq - deq ){
        int u = cola[deq++];
        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];
            if( !lev[v] ){
                lev[v] = lev[u] + 1;
                cola[enq++] = v;
            }
        }
	}

	for( int i = enq-1; i >= 0; i-- ){
        int u = cola[i];
        for( int j = 0; j < g[u].size(); j++ ){
            int v = g[u][j];
            if( lev[v] > lev[u] ){
                if( !sol[v] ){
                    sol[u] = true;
                    break;
                }
            }
        }
	}

	if( sol[1] ){
        cout << "Vladimir\n";
	}
	else{
        cout << "Nikolay\n";
	}
}

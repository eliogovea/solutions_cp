// 2016-2017 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101137G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int k[MAXN];
int now[MAXN];
vector<int> g[MAXN];

vector<int> cycle;

void dfs( int u ){
    for( ; now[u] < g[u].size(); ){
        int v = g[u][ now[u] ];
        now[u]++;
        dfs( v );
    }

    cycle.push_back( u );
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	k[0] = 1;
	for( int i = 1; i <= n; i++ ){
        k[i] = i;
	}

	for( int u = 1; u <= n; u++ ){
        for( int v = 1; v <= n; v++ ){
            if( u == v || (u == 2 && v == 1) ){
                continue;
            }
            g[u].push_back(v);
        }
	}

	g[0].push_back(1);
	g[2].push_back(0);

	dfs(0);
	reverse( cycle.begin() , cycle.end() );

	for( int i = 0; i < cycle.size()-1; i++ ){
        int u = cycle[i];
        int v = cycle[i+1];
        cout << v << ' ' << k[v] << ' ' << u << '\n';
	}
}

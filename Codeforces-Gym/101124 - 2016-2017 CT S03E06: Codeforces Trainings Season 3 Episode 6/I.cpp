// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124I

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 1000100;

vector<int> g[MAXN];
bool mk[MAXN];

int ady[2*MAXN];

vector<int> sol;

bool ok( int u ){
    mk[u] = true;
    int d = 0;

    for( int i = 0; i < g[u].size(); i++ ){
        int e = g[u][i];
        int v = ady[e];

        if( !mk[v] ){
            if( !ok(v) ){
                d++;
                sol.push_back( e );
            }
        }
    }

    return ( d % 2 != 0 );
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

    int n, m; cin >> n >> m;

    int E = 2;

    for( int i = 0; i < m; i++ ){
        int u, v; cin >> u >> v;

        ady[E] = v;
        g[u].push_back(E++);
        ady[E] = u;
        g[v].push_back(E++);
    }

    for( int i = 1; i <= n; i++ ){
        if( !mk[i] ){
            if( !ok(i) ){
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << sol.size() << '\n';

    for( int i = 0; i < sol.size(); i++ ){
            int e = sol[i];
            if( e % 2 != 0 ){
                e--;
            }
        cout << ady[e+1] << ' ' << ady[e] << '\n';
    }
}

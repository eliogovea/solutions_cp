// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507B

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];

bool mk[MAXN];
int k[MAXN];
int IN[MAXN];
int OUT[MAXN];

void dfs( int u, int in ){
    if( !mk[u] ){
        mk[u] = true;

        IN[u] = in;
        OUT[u] = k[u];
    }
    else{
        if( in == IN[u] || IN[u] == -1  ){
            return;
        }

        IN[u] = -1;
    }

    if( !k[u] ){
        OUT[u] = IN[u];
    }

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        dfs( v , OUT[u] );
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> k[i];

        int m; cin >> m;
        for( int j = 1; j <= m; j++ ){
            int v; cin >> v;
            g[i].push_back(v);
        }
    }

    dfs(1,0);

    for( int i = 1; i <= n; i++ ){
        if( IN[i] == 0 ){
            cout << "sober";
        }
        else if( IN[i] == -1 ){
            cout << "unknown";
        }
        else{
            cout << IN[i];
        }

        cout << ' ';

        if( OUT[i] == 0 ){
            cout << "sober";
        }
        else if( OUT[i] == -1 ){
            cout << "unknown";
        }
        else{
            cout << OUT[i];
        }

        cout << '\n';
    }
}

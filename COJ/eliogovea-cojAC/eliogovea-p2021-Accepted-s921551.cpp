/// sUrPRise

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

const int MOD = 1000000000;

int n, m;
vector <int> g[N];
vector <int> gi[N];

bool mark[N];
bool toend[N];
vector<int> topo;
int mk[N];
void topological( int u ){
    mk[u] = true;
    if( !toend[u] ){
        return;
    }

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !toend[v] || mk[v] ) continue;
        topological( v );
    }

    topo.push_back( u );
}



void dfs(int u) {
    mark[u] = true;
    if (u == 2) {
        toend[u] = true;
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!mark[v]) {
            dfs(v);
        }
        if (toend[v]) {
            toend[u] = true;
        }
    }
}

int mark1[N];

bool mayor = false;

long long dp[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        gi[y].push_back(x);
    }

    dfs(1);

    if (!mark[2]) {
        cout << "0\n";
        return 0;
    }
    topological(1);
    reverse(topo.begin(), topo.end());
    assert(topo[0] = 1);
    assert(topo.back() == 2);
    bool cycle = false;
    mark1[1] = true;
    for (int i = 1; i + 1 < topo.size(); i++) {
        for (int j = 0; j < g[topo[i]].size(); j++) {
            int v = g[topo[i]][j];
            if (toend[v]) {
                if (mark1[v]) {
                    cycle = true;
                    break;
                }
            }
        }
        mark1[topo[i]] = true;
        if (cycle) {
            break;
        }
    }

    if (cycle) {
        cout << "inf\n";
        return 0;
    }

    dp[1] = 1;
    for (int i = 0; i + 1 < topo.size(); i++) {
        for (int j = 0; j < g[topo[i]].size(); j++) {
            int v = g[topo[i]][j];
            dp[v] += dp[topo[i]];
            if (dp[v] >= MOD) {
                mayor = true;
            }
            if (mayor) {
                dp[v] %= MOD;
            }
        }
    }

    if (!mayor) {
        cout << dp[2] << "\n";
        return 0;
    }

    vector <int> ans;
    int x = dp[2];
    while (x) {
        ans.push_back(x % 10);
        x /= 10;
    }

    while (ans.size() < 9) {
        ans.push_back(0);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << "\n";

    //copy( topo.begin(), topo.end(), ostream_iterator<int>( cout, " " ) ); cout << endl;

}

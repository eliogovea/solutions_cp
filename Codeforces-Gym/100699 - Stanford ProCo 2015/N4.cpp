// Stanford ProCo 2015
// 100699N4

#include <bits/stdc++.h>

using namespace std;

int n;
int par[105], val[105];
int cnt[105], sum[105];

vector<int> g[105];

int ans = -1;

void dfs(int u) {
    cnt[u] = 1;
    sum[u] = val[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == par[u]) {
            continue;
        }
        dfs(v);
        cnt[u] += cnt[v];
        sum[u] += sum[v];
    }
    if (ans == -1 || sum[u] * cnt[ans] > sum[ans] * cnt[u]) {
        ans = u;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> par[i] >> val[i];
        g[par[i]].push_back(i);
    }
    dfs(1);

    cout.precision(3);
    cout << fixed << 1.0 * sum[ans] / cnt[ans] << "\n";
}

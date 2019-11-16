#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int E = 55;

int n, e;
int d[E][E];

int ef[N];

vector <int> g[N];

long long dp[E][N];

long long calc(int u, int p, int t) {
    if (dp[t][u] != -1) {
        return dp[t][u];
    }
    long long res = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) {
            continue;
        }
        if (ef[v] != 0) {
            res += d[t][ef[v]] + calc(v, u, ef[v]);
        } else {
            long long val = -1;
            for (int j = 1; j <= e; j++) {
                long long tmp = calc(v, u, j) + d[t][j];
                if (val == -1 || tmp < val) {
                    val = tmp;
                }
            }
            res += val;
        }

    }
    dp[t][u] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= e; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x;
        while (x--) {
            cin >> y;
            ef[y] = i;
        }
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= e; j++) {
            dp[j][i] = -1;
        }
    }
    long long ans = -1;

    if (ef[1] != 0) {
        ans = calc(1, 1, ef[1]);
    } else {
        for (int i = 1; i <= e; i++) {
            long long best = calc(1, 1, i);
            if (ans == -1 || best < ans) {
                ans = best;
            }
        }
    }
    cout << ans << "\n";
}

// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861H

#include <bits/stdc++.h>

using namespace std;

const int N = 80;
const long long INF = 1e15;

int n, m;
long long g[N][N];
long long ng[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = INF;
        }
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        long long t;
        cin >> x >> y >> t;
        x--;
        y--;
        g[x][y] = g[y][x] = min(g[x][y], t);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    long long bfg0 = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            bfg0 = max(bfg0, g[x][y]);
        }
    }

    // cerr << "bfg0: " << bfg0 << "\n";

    long long ans_bfg = bfg0;
    long long ans_time = -1;

    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            long long bfg = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    ng[x][y] = min(g[x][y], min(g[x][u] + g[v][y], g[x][v] + g[u][y]));
                    bfg = max(bfg, ng[x][y]);
                }
            }

            if (bfg == INF) {
                continue;
            }

            if (bfg > ans_bfg) {
                continue;
            }

            // cerr << u << " " << v << " " << bfg << "\n";

            long long t = INF;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (g[x][y] <= bfg) {
                        continue;
                    }
                    long long d = bfg - min(g[x][u] + g[v][y], g[x][v] + g[u][y]);
                    // cerr << "!!!!!!! " << x << " " << y << " " << d << "\n";
                    t = min(t, d);
                }
            }

            if (bfg < ans_bfg || (bfg == ans_bfg && t > ans_time)) {
                ans_bfg = bfg;
                ans_time = t;
            }
        }
    }

    if (ans_bfg == INF) {
        cout << "-1.00000 ";
    } else {
        cout << ans_bfg << ".00000 ";
    }
    if (ans_time == INF) {
        cout << "-1.00000";
    } else {
        cout << ans_time << ".00000";
    }
    cout << "\n";
}

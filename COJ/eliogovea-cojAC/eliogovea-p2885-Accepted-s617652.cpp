#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int n, m, col[MAXN], G[MAXN][MAXN];

int main() {
    while (scanf("%d%d", &n, &m) && n | m) {
        for (int i = 0; i < n; i++)
            scanf("%d", &col[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) G[i][j] = (i != j) ? 1 << 29 : 0;

        for (int i = 0, a, b; i < m; i++) {
            scanf("%d%d", &a, &b);
            a--; b--;
            if (col[a] != col[b]) G[a][b] = G[b][a] = 1;
            else G[a][b] = G[b][a] = 0;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    G[i][j] = G[j][i] = min(G[i][j], G[i][k] + G[j][k]);

        int sol = 1 << 29;
        for (int i = 0; i < n; i++) {
            int mx = -1;
            for (int j = 0; j < n; j++) mx = max(mx, G[i][j]);
            sol = min(sol, mx);
        }
        printf("%d\n", sol);
    }
}

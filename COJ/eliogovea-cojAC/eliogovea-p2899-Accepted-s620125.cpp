#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, m, a, b, k, g, bi[MAXN][MAXN], bf[MAXN][MAXN], gw[MAXN], t[MAXN], tg[MAXN],
    cost[MAXN][MAXN];
vector<int> ady[MAXN];
vector<int>::iterator it;
priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > Q;
bool mark[MAXN];

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &k, &g);
    for (int i = 0; i < g; i++) scanf("%d", &gw[i]);
    for (int i = 0, x, y, z; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        cost[x][y] = z;
        cost[y][x] = z;
        ady[x].push_back(y);
        ady[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) tg[i] = 1 << 29;
    int tot = 0;
    for (int i = 1; i < g; i++) {
        bi[ gw[i] ][ gw[i - 1] ] = bi[ gw[i - 1] ][ gw[i] ] = tot;
        tot += cost[ gw[i] ][ gw[i - 1] ];
        bf[ gw[i] ][ gw[i - 1] ] = bf[ gw[i - 1] ][ gw[i] ] = tot;
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", bf[i][j]);
        printf("\n");
    }*/

    for (int i = 1; i <= n; i++) t[i] = 1 << 29;
    t[a] = k;
    Q.push(make_pair(k, a));
    while (!Q.empty()) {
        int u = Q.top().second;
        //printf(">>%d\n", u);
        Q.pop();
        if (mark[u]) continue;
        mark[u] = 1;
        for (it = ady[u].begin(); it != ady[u].end(); it++) {
            //printf(">>>%d %d %d %d\n", *it, t[u], bi[u][*it], bf[u][*it]);

            if (t[u] < bi[u][*it] || t[u] > bf[u][*it]) {
                if (t[*it] > t[u] + cost[u][*it]) {
                    t[*it] = t[u] + cost[u][*it];
                    Q.push(make_pair(t[*it], *it));
                }
            }

            else {
                if (t[*it] > bf[u][*it] + cost[u][*it]) {
                    t[*it] = bf[u][*it] + cost[u][*it];
                    Q.push(make_pair(t[*it], *it));
                }
            }
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", t[i]);
    printf("%d\n", t[b] - k);
}

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

string s[N];
int n;

int ady[N], cap[N], flow[N], nxt[N], last[N], now[N];

int E;

inline void add(int a, int b, int c) {
    ady[E] = b; cap[E] = c; flow[E] = 0; nxt[E] = last[a]; last[a] = E++;
    ady[E] = a; cap[E] = c; flow[E] = 0; nxt[E] = last[b]; last[b] = E++;
}

int lev[N];

queue <int> Q;

int source, sink;

bool bfs() {
    for (int i = 0; i < n; i++) {
        lev[i] = -1;
    }
    lev[source] = 0;
    Q.push(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int e = last[u]; e != -1; e = nxt[e]) {
            if (cap[e] > flow[e]) {
                int v = ady[e];
                if (cap[e] > flow[e]) {
                    if (lev[v] == -1) {
                        lev[v] = lev[u] + 1;
                        Q.push(v);
                    }
                }
            }

        }
    }
    return (lev[sink] != -1);
}

int dfs(int u, int f) {
    if (u == sink) {
        return f;
    }
    for (int e = now[u]; e != -1; e = now[u] = nxt[e]) {
        if (cap[e] > flow[e]) {
            int v = ady[e];
            if (lev[v] == lev[u] + 1) {
                int ff = min(f, cap[e] - flow[e]);
                int res = dfs(v, ff);
                if (res > 0) {
                    flow[e] += res;
                    flow[e ^ 1] -= res;
                    return res;
                }
            }
        }
    }
    return 0;
}

int maxflow() {
    int res = 0;
    while (bfs()) {
        for (int i = 0; i < n; i++) {
            now[i] = last[i];
        }
        while (true) {
            int tmp = dfs(source, 1e7);
            if (tmp == 0) {
                break;
            }
            res += tmp;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    while (cin >> s[0]) {
        n = s[0].size();
        for (int i = 1; i < n; i++) {
            cin >> s[i];
        }
        int ans = 0;
        for (sink = 1; sink < n; sink++) {
            E = 0;
            for (int i = 0; i < n; i++) {
                last[i] = -1;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    add(i, j, s[i][j] - '0');
                }
            }
            int x = maxflow();
            if (sink == 1 || x < ans) {
                ans = x;
            }
        }
        cout << ans << "\n";
    }
}

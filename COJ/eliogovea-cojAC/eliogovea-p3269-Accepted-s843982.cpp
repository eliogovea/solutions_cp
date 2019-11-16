#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;

vector <int> g[N];

int depth[N], size[N], head[N], chain[N], heavy[N], par[N];

struct ST {
    int n;
    vector <int> t;
    vector<int> lazy;
    ST() {}
    ST(int _n) {
        n = _n;
        t.clear(); lazy.clear();
        t.resize(4 * n); lazy.resize(4 * n);
    }
    void push(int x, int l, int r) {
        if (lazy[x]) {
            t[x] = r - l + 1 - t[x];
            if (l != r) {
                lazy[x + x] ^= 1;
                lazy[x + x + 1] ^= 1;
            }
            lazy[x] = 0;
        }
    }
    void update(int x, int l, int r, int ul, int ur) {
        push(x, l, r);
        if (l > ur || r < ul) {
            return;
        }
        if (l >= ul && r <= ur) {
            lazy[x] ^= 1;
            push(x, l, r);
        } else {
            int m = (l + r) >> 1;
            update(x + x, l, m, ul, ur);
            update(x + x + 1, m + 1, r, ul, ur);
            t[x] = t[x + x] + t[x + x + 1];
        }
    }
    void update(int l, int r) {
        return update(1, 1, n, l, r);
    }
    int query(int x, int l, int r, int ql, int qr) {
        push(x, l, r);
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return t[x];
        int m = (l + r) >> 1;
        int q1 = query(x + x, l, m, ql, qr);
        int q2 = query(x + x + 1, m + 1, r, ql, qr);
        return q1 + q2;
    }
    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

vector<ST> chains;

void dfs(int u, int p, int d) {
    depth[u] = d;
    par[u] = p;
    size[u] = 1;
    heavy[u] = -1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u, d + 1);
        size[u] += size[v];
        if (heavy[u] == -1 || size[v] > size[heavy[u]]) heavy[u] = v;
    }
}

void HLD() {
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || heavy[par[i]] != i) {
            int cnt = 0;
            for (int j = i; j != -1; j = heavy[j]) {
                cnt++;
                chain[j] = chains.size();
                head[j] = i;
            }
            chains.push_back(ST(cnt));
        }
    }
}

void update(int u, int v) {

    while (chain[u] != chain[v]) {
        if (depth[head[u]] > depth[head[v]]) {
            chains[ chain[u] ].update(1, depth[u] - depth[head[u]] + 1);
            u = par[head[u]];
        } else {
            chains[  chain[v] ].update(1, depth[v] - depth[head[v]] + 1);
            v = par[head[v]];
        }
    }
    if (depth[u] > depth[v]) swap(u, v);
    chains[ chain[u] ].update(depth[u] - depth[ head[u] ] + 1, depth[v] - depth[ head[v] ] + 1);
}

int query(int u, int v, int &lca) {
    int res = 0;
    while (chain[u] != chain[v]) {
        if (depth[head[u]] > depth[head[v]]) {
            res += chains[ chain[u] ].query(1, depth[u] - depth[head[u]] + 1);
            u = par[head[u]];
        } else {
            res += chains[ chain[v] ].query(1, depth[v] - depth[head[v]] + 1);
            v = par[head[v]];
        }
    }
    if (depth[u] > depth[v]) swap(u, v);
    lca = u;
    res += chains[ chain[u] ].query( depth[u] - depth[head[u]] + 1, depth[v] - depth[head[v]] + 1 );
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    int x, y, z;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    HLD();
    int q;
    cin >> q;
    while (q--) {
        cin >> x >> y >> z;
        if (x == 1) {
            update(y, z);
        } else {
            int lca;
            int ans = query(y, z, lca);
            ans = depth[y] + depth[z] - 2 * depth[lca] + 1 - ans;
            cout << ans << "\n";
        }
    }
}

// 2012-2013 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100685G

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
vector <pair <int, int> > g[N];
int tin[N], tout[N], ttt;
int sum[N];
int par[22][N];
int depth[N];

void dfs(int u, int p, int s, int d) {
    tin[u] = ttt++;
    par[0][u] = p;
    sum[u] = s;
    depth[u] = d;
    for (int i = 1; i < 20; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        if (v == p) continue;
        dfs(v, u, s + g[u][i].second, d + 1);
    }
    tout[u] = ttt++;
}

bool anc(int a, int b) {
    return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

int lca(int a, int b) {
    if (anc(a, b)) return a;
    for (int i = 19; i >= 0; i--) {
        if (!anc(par[i][a], b)) {
            a = par[i][a];
        }
    }
    return par[0][a];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(make_pair(b, 1));
        g[b].push_back(make_pair(a, 0));
    }
    dfs(0, 0, 0, 0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int _lca = lca(a, b);
        int suma = sum[a] - sum[_lca];
        int lena = depth[a] - depth[_lca];
        int sumb = sum[b] - sum[_lca];
        int lenb = depth[b] - depth[_lca];
        cout << ((suma == 0 && sumb == lenb) ? "Yes" : "No") << "\n";
    }
}

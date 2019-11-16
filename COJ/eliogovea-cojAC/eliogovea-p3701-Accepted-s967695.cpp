#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
vector <int> g[N];
int depth[N];

int cycle = -1;

void dfs(int u, int p, int d) {
	depth[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != p) {
			if (depth[v] == -1) {
				dfs(v, u, d + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(7);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		depth[i] = -1;
	}
	dfs(1, 0, 0);

	for (int u = 1; u <= n && cycle == -1; u++) {
        for (int i = 0; i < g[u].size() && cycle == -1; i++) {
            int v = g[u][i];
            if (depth[v] < depth[u] - 1) {
                //cerr << u << " " << v << " " << depth[u] - depth[v] + 1 << "\n";
                cycle = depth[u] - depth[v] + 1;
            }
        }
	}
	//cerr << cycle << "\n";
	assert(cycle != -1);
	double ans = ((double)n + (double)cycle) / (double)n;
	cout << fixed << ans << "\n";
}

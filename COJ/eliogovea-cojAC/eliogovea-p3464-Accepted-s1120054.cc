#include <bits/stdc++.h>

using namespace std;

const int N = 10 * 1000 + 10;

int t;
int n;
vector <int> g[N];
int dist1[N], dist2[N];

void dfs(int u, int p, int d, int *dist) {
	dist[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) {
			continue;
		}
		dfs(v, u, d + 1, dist);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(0, -1, 0, dist1);
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (dist1[i] > dist1[x]) {
                x = i;
            }
        }
        dfs(x, -1, 0, dist2);
        int y = 0;
        for (int i = 0; i < n; i++) {
            if (dist2[i] > dist2[y]) {
                y = i;
            }
        }

        cout << dist2[y] + 1 << "\n";
	}
}

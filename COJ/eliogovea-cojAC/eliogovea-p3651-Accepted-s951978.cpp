#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int t;
int n, m, a, b;
int g[105][105];
int mx[105];
bool center[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = INF;
			}
			g[i][i] = 0;
		}
		while (m--) {
			int x, y, z;
			cin >> x >> y >> z;
			if (g[x][y] > z) {
				g[x][y] = g[y][x] = z;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		int dist = -1;
		for (int i = 1; i <= n; i++) {
			int mxx = 0;
			for (int j = 1; j <= n; j++) {
				mxx = max(mxx, g[i][j]);
			}
			mx[i] = mxx;
			if (dist == -1 || mxx < dist) {
				dist = mxx;
			}
		}
		for (int i = 1; i <= n; i++) {
			center[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			if (mx[i] == dist) {
				center[i] = true;
			}
		}
		int dist1 = -1;
		int dist2 = -1;
		for (int i = 1; i <= n; i++) {
			if (center[i]) {
				if (dist1 == -1 || g[a][i] < dist1) {
					dist1 = g[a][i];
				}
				if (dist2 == -1 || g[b][i] < dist2) {
					dist2 = g[b][i];
				}
			}
		}
		if (dist1 < dist2) {
			cout << "Kimo is ";
		} else if (dist1 == dist2) {
			cout << "Both are ";
		} else {
			cout << "Jose is ";
		}
		cout << "right\n";
	}
}

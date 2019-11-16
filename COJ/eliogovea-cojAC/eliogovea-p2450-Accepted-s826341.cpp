#include <bits/stdc++.h>

using namespace std;

int t;
int n, x[50005], y[50005];
int xx[50005], yy[50005];

vector<int> g[50005];
int match[50005];
int used[50005], id;

bool kuhn(int u) {
	if (used[u] == id) {
		return false;
	}
	used[u] = id;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (match[v] == -1 || kuhn(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			xx[i] = x[i];
			yy[i] = y[i];
		}
		sort(xx, xx + n);
		sort(yy, yy + n);
		int cntx = unique(xx, xx + n) - xx;
		int cnty = unique(yy, yy + n) - yy;
		for (int i = 0; i < cntx; i++) {
			g[i].clear();
		}
		for (int i = 0; i < cnty; i++) {
			match[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			int px = lower_bound(xx, xx + cntx, x[i]) - xx;
			int py = lower_bound(yy, yy + cnty, y[i]) - yy;
			g[px].push_back(py);
		}
		int ans = 0;
		for (int i = 0; i < cntx; i++) {
			id++;
			if (kuhn(i)) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}

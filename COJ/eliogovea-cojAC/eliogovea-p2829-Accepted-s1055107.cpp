#include <bits/stdc++.h>

using namespace std;

const int N = 10 * 1000 + 5;

int n, t, l;
int p[N], r[N];
vector <int> g[N];
int depth[N];

void dfs(int u, int d) {
	depth[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(v, d + 1);
	}
}

inline int getGrundy(int c, int l) {
	return c % (l + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> t >> l;
	for (int i = 1; i < n; i++) {
		cin >> p[i] >> r[i];
		p[i]--;
		g[p[i]].push_back(i);
	}

	dfs(0, 0);

	int xorSum = 0;
	for (int i = 0; i < n; i++) {
		if (depth[i] & 1) {
			xorSum ^= getGrundy(r[i], l);
		}
	}

	while (t--) {
		int a, b;
		cin >> a >> b;
		a--;
		if (depth[a] & 1) {
			xorSum ^= getGrundy(r[a], l);
			r[a] = b;
			xorSum ^= getGrundy(r[a], l);
		}
		cout << ((xorSum != 0) ? "Yes" : "No") << "\n";
	}
}

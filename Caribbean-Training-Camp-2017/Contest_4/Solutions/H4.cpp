#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 10;

int n, m;
vector <int> g[N];

bool vis[N];
int match[N];

bool dfs(int u) {
	if (vis[u]) {
		return false;
	}
	vis[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

bool matchedL[N], matchedR[N];

vector <int> g1[2 * N];

bool ok[2 * N];

bool used[2 * N];

bool dfs2(int u) {
    // cerr << "-->> " << u << "\n";
	if (u <= n && !matchedL[u]) {
		return true;
	}
	used[u] = true;
	for (int i = 0; i < g1[u].size(); i++) {
		int v = g1[u][i];
		if (!used[v]) {
			if (dfs2(v)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input001.txt", "r", stdin);

	cin >> n >> m;
	string line;
	getline(cin, line);
	for (int i = 1; i <= n; i++) {
		getline(cin, line);
		stringstream in(line);
		int x;
		while (in >> x) {
			g[i].push_back(x);
		}
	}

	for (int i = 1; i <= m; i++) {
		match[i] = -1;
	}

    int mt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[j] = false;
		}
		mt += dfs(i);
	}
	// cerr << "max match " << mt << "\n";

	for (int i = 1; i <= m; i++) {
		if (match[i] != -1) {
            // cerr << match[i] << " " << i << "\n";
			matchedL[match[i]] = true;
			matchedR[i] = true;
			ok[match[i]] = true;
		}
	}

	for (int u = 1; u <= n; u++) {
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (match[v] == u) {
                // cerr << "to left " << u << " " << v << "\n";
				g1[u].push_back(n + v);
			} else {
			    // cerr << "to right " << u << " " << v << "\n";
				g1[n + v].push_back(u);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (matchedL[i]) {
			for (int i = 1; i <= n + m; i++) {
				used[i] = false;
			}
			// cerr << "start dfs\n";
			if (dfs2(i)) {
				ok[i] = false;
			}
		}
	}

	vector <int> ans;
	for (int i = 1; i <= n; i++) {
		if (ok[i]) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector <int> f(n), t(n);
	vector <vector <int>> adj(n);

	for (int i = 0; i < n; i++) {
		cin >> f[i] >>t[i];
		f[i]--;
		if (f[i] >= 0) {
			adj[f[i]].push_back(i);
		}
	}

	vector <vector <int>> cnt(n, vector <int> (2, 0));

	vector <int> dp(n);

	function <void(int)> dfs = [&](int u) {
		cnt[u][t[u]]++;
		for (auto v : adj[u]) {
			dfs(v);
			cnt[u][0] += cnt[v][0];
			cnt[u][1] += cnt[v][1];
		}

		int x = 0;
		for (auto v : adj[u]) {
			x += dp[v];
		}
		dp[u] = max(0, max(cnt[u][1] - cnt[u][0], x));
	};

	int answer = 0;

	for (int u = 0; u < n; u++) {
		if (f[u] == -1) {
			dfs(u);
			answer += dp[u];
		}
	}

	cout << answer << "\n";
}

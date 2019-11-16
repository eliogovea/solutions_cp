#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int t;
int n;
int s[N], e[N], v[N];

int vals[2 * N];

vector <pair <int, int> > graph[2 * N];
int dp[2 * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> e[i] >> v[i];
			e[i] += s[i];
			vals[i] = s[i];
			vals[n + i] = e[i];
		}
		sort(vals, vals + 2 * n);
		int cnt = unique(vals, vals + 2 * n) - vals;
		for (int i = 0; i <= cnt; i++) {
			graph[i].clear();
			dp[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			s[i] = 1 + lower_bound(vals, vals + cnt, s[i]) - vals;
			e[i] = 1 + lower_bound(vals, vals + cnt, e[i]) - vals;
			graph[e[i]].push_back(make_pair(s[i], v[i]));
		}
		for (int i = 1; i <= cnt; i++) {
			dp[i] = dp[i - 1];
			for (int j = 0; j < graph[i].size(); j++) {
				dp[i] = max(dp[i], dp[graph[i][j].first - 1] + graph[i][j].second);
			}
		}
		cout << dp[cnt] << "\n";
	}
}

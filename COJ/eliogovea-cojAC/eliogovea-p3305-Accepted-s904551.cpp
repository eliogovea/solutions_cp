#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

const long long INF = 1e16;

int n, k;
long long x[N];
long long sx[N];
long long dp[3][N];
int pos[3][N];

inline long long cost(int l, int r) {
	int p = (l + r) >> 1;
	return x[p] * (long long)(p - l + 1LL) - (sx[p] - sx[l - 1]) + sx[r] - sx[p - 1] - x[p] * (long long)(r - p + 1LL);
}

void solve(int cur, int l, int r, int pl, int pr) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	for (int i = pl; i <= pr && i < mid; i++) {
		if (dp[cur][mid] == -1 || dp[cur][mid] > dp[cur ^ 1][i] + cost(i + 1, mid)) {
			dp[cur][mid] = dp[cur ^ 1][i] + cost(i + 1, mid);
			pos[cur][mid] = i;
		}
	}
	solve(cur, l, mid - 1, pl, pos[cur][mid]);
	solve(cur, mid + 1, r, pos[cur][mid], pr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		sort(x + 1, x + n + 1);
		for (int i = 1; i <= n; i++) {
			sx[i] = sx[i - 1] + x[i];
		}
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			dp[cur][i] = cost(1, i);
			pos[cur][i] = 0;
		}
		long long ans = dp[cur][n];
		for (int i = 2; i <= k; i++) {
			cur ^= 1;
			for (int i = 0; i <= n; i++) {
				dp[cur][i] = INF;
				pos[cur][i] = 0;
			}
			solve(cur, i, n, i - 1, n);
			ans = min(ans, dp[cur][n]);
		}
		cout << ans << "\n";
	}
}

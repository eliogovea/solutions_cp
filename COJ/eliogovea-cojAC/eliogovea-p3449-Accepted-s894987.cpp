#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n;
string s[505];
string sensei;

int dp[2][1 << 14];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> sensei;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int cur = 0;
	dp[cur][0] = 1;
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < 12; j++) {
			if (s[i][j] >= sensei[j]) {
				mask |= (1 << j);
			}
		}
		for (int j = 0; j < (1 << 12); j++) {
			dp[cur ^ 1][j] = dp[cur][j];
		}
		for (int j = 0; j < (1 << 12); j++) {
			add(dp[cur ^ 1][j | mask], dp[cur][j]);
		}
		cur ^= 1;
	}
	int ans = 0;
	for (int i = 0; i < (1 << 12); i++) {
		int cnt = 0;
		for (int j = 0; j < 12; j++) {
			if (i & (1 << j)) {
				cnt++;
			}
		}
		if (cnt > 6) {
            add(ans, dp[cur][i]);
		}
	}
	cout << ans << "\n";
}

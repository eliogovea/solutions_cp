#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

const int N = 9 * 500;

bool sieve[N + 5];

int dp[505][9 * 505][3];

int solve(string &n, int pos, int sum, bool eq) {
	if (pos == (int)n.size()) {
		return !sieve[sum];
	}
	if (dp[pos][sum][eq] != -1) {
		return dp[pos][sum][eq];
	}
	int res = 0;
	if (eq) {
		for (int d = 0; d < n[pos] - '0'; d++) {
			add(res, solve(n, pos + 1, sum + d, false));
		}
		add(res, solve(n, pos + 1, sum + n[pos] - '0', true));
	} else {
		for (int d = 0; d <= 9; d++) {
			add(res, solve(n, pos + 1, sum + d, false));
		}
	}
	dp[pos][sum][eq] = res;
	return res;
}

int solve(string &s) {
	for (int p = 0; p <= (int)s.size(); p++) {
		for (int s = 0; s <= 9 * p; s++) {
			for (int e = 0; e < 2; e++) {
				dp[p][s][e] = -1;
			}
		}
	}
	return solve(s, 0, 0, true);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	sieve[0] = sieve[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = true;
			}
		}
	}
	string l, r;
	while (cin >> l >> r) {
		int ans = solve(r);
		add(ans, MOD - solve(l));
		int sum = 0;
		for (int i = 0; i < l.size(); i++) {
			sum += l[i] - '0';
		}
		if (!sieve[sum]) {
			add(ans, 1);
		}
		cout << ans << "\n";
	}
}

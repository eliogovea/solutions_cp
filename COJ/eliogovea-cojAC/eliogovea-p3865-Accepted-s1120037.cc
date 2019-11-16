#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector <int> c(1 << n);
	vector <int> t(1 << n);
	c[0] = 0;
	t[0] = 1;
	for (int i = 0; i < n; i++) {
		c[1 << i] = 1;
		t[1 << i] = v[i];
	}
	for (int m = 1; m < (1 << n); m++) {
		c[m] = c[m ^ (m & -m)] + 1;
		t[m] = mul(t[m ^ (m & -m)], t[m & -m]);
	}

	vector <long long> dp(1 << n, -1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[1 << i] = 0;
	}
	for (int m = 1; m < (1 << n); m++) {
		int sm = (m - 1) & m;
		while (sm != 0) {
			long long val = dp[sm] + dp[m ^ sm] + (long long)c[sm] * t[sm] + (long long)c[m ^ sm] * t[m ^ sm];
			if (dp[m] == -1 || val < dp[m]) {
				dp[m] = val;
			}
			sm = (sm - 1) & m;
		}
	}

	cout << dp[(1 << n) - 1] << "\n";
}

// Problem: pace=1&num=1586
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 9;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n;

int dp[105][10005];

bool criba[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < 1000; i++) {
		if (!criba[i]) {
			for (int j = i + i; j < 1000; j += i) {
				criba[j] = true;
			}
		}
	}
	criba[0] = criba[1] = true;
	cin >> n;
	for (int i = 100; i < 1000; i++) {
		if (!criba[i]) {
			add(dp[i % 100][3], 1);
		}
	}
	for (int i = 3; i < n; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 1; k < 10; k += 2) {
				if (10 * j + k >= 100) {
					if (!criba[10 * j + k]) {
						add(dp[10 * (j % 10) + k][i + 1], dp[j][i]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		add(ans, dp[i][n]);
	}
	cout << ans << "\n";
}

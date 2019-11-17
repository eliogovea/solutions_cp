// Problem: pace=1&num=1044
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;

ll dp[N][10 * N];

int n, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i < n / 2; i++) {
		for (int j = 0; j <= 9 * i; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[i + 1][j + k] += dp[i][j];
			}
		}
	}
	ll t = 0;
	for (int i = 0; i <= 9 * (n / 2); i++) {
        t += dp[n / 2][i] * dp[n / 2][i];
	}
	if (n & 1) {
        t *= 10;
	}
	cout << t << "\n";
}

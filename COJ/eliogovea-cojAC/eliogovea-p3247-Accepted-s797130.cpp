#include <bits/stdc++.h>

using namespace std;

const long long mod = 100000007;

const int N = 1000;

int n;
long long dp[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * i + ((i & 1) ? 1 : -1) + mod) % mod;
	}
	while (cin >> n && n) {
		cout << dp[n] << "\n";
	}
}

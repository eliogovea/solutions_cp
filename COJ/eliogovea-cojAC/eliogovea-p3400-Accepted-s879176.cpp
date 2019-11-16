#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
const int K = 12;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int n, k, a[N];
int dp[K][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	long long S = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		S += a[i];
	}
	S /= k;
	for (int i = 0; i <= n; i++) dp[0][i] = 1;
	for (int i = 1; i <= k; i++) {
		long long sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += a[j];
			dp[i][j] = dp[i][j - 1];
			if (sum == (long long)i * S) {
				add(dp[i][j], dp[i - 1][j - 1]);
			}
		}
	}
	int ans = dp[k][n];
	add(ans, MOD - dp[k][n - 1]);
	cout << ans << "\n";
	return 0;
}

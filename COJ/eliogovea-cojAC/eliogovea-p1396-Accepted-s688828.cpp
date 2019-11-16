#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef unsigned long long LL;

int tc, n, k;
LL dp[101][101][101];

LL solve(LL n, LL k) {
	if ((n & 1LL) || (k == 0)) return 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int l = 0; l < k; l++)
				dp[i][j][l] = 0;
	dp[0][0][0] = 1LL;
	for (LL i = 0; i < n; i++)
		for (LL j = 0; j < n; j++) {
			for (LL l = 0; l < k; l++) {
				dp[i + 1][j + 1][(l + (1LL << i) % k) % k] += dp[i][j][l];
				if (i != n - 1) dp[i + 1][j][l] += dp[i][j][l];
			}
		}
	return dp[n][n / 2][0];
}

int s(int n, int k) {
	int ret = 0;
	for (int i = 0; i < (1 << n); i++) {
		LL num = 0, cnt = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				cnt++;
				num += (1 << j);
			}
		if (cnt + cnt == n && num % k == 0 && (num & (1 << (n - 1)))) {
			//cout << num << "\n";
			ret++;
		}
	}
	return ret;
}

void check() {
	for (int i = 0; i < 300; i++) {
			srand(i);
			n = 2 * (1 + (rand() % 5));
			k = rand() % 101;
			//cout << n << " " << k << "\n";
			int a = solve(n, k);
			int b = s(n, k);
			if (a != b) cout << "error ";
			cout << n << " " << k << " " << a << " " << b << "\n";
		}
}

int main() {
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n >> k;
		cout << "Case " << i << ": " << solve(n, k) << "\n";
	}
}

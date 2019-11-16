#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1000005;

long long l, s, t, dp[N];

int main() {
	cin >> l >> s >> t;
	dp[0] = 1;
	for (int i = 1; i <= l; i++) {
		dp[i] = 0;
		if (i >= s) {
			dp[i] += dp[i - s];
			dp[i] %= mod;
		}
		if (i >= t) {
			dp[i] += dp[i - t];
			dp[i] %= mod;
		}
	}
	cout << dp[l] << "\n";
}

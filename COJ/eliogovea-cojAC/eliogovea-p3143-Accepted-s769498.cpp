#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;

int n;
long long dp[505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	dp[1] = 1;
	for (long long i = 2; i <= n; i++) {
		dp[i] = ((i - 1) * dp[i - 1] + (i - 2) * dp[i - 2]) % mod;
	}
	cout << dp[n] << "\n";
}

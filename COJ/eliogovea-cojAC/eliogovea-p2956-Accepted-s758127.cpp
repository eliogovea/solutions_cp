#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 2000;

long long k, n, c[N + 5][N + 5], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		c[i][0] = c[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	while (cin >> n >> k) {
		ans = 1;
		k = n / k;
		for (int i = n; i > 0; i -= k) {
			ans = (ans * c[i][k]) % mod;
		}
		cout << ans << "\n";
	}
}

#include <bits/stdc++.h>

using namespace std;

int t, cas, n, k;

unsigned long long f[25];
unsigned long long c[25][25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1;
	for (int i = 1; i <= 20; i++) {
		f[i] = f[i - 1] * (long long)i;
	}
	for (int i = 0; i <= 20; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cin >> t;
	while (t--) {
		cin >> cas >> n >> k;
		unsigned long long ans = 0;
		if (k == 1) {
			cout << cas << " " << f[n - 1] << "\n";
			continue;
		}
		for (int x = 0; x + 2 <= k; x++) {
			ans += c[k - 2][x] * f[x + 2 - 1] * f[n - (x + 2)];
		}
		cout << cas << " " << ans << "\n";
	}
}

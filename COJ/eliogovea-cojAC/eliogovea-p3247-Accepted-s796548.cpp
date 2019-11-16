#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000;

const ll mod = 100000007;

ll f[N + 5];
ll c[N + 5][N + 5];

int t, n;
ll s[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = (f[i - 1] * i) % mod;
	}
	for (int i = 0; i <= N; i++) {
		c[i][0] = c[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	for (int i = 1; i <= N; i++) {
		s[i] = -1;
	}
	while (cin >> n && n) {
		if (s[n] != -1) {
			cout << s[n] << "\n";
			continue;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ll tmp = (c[n][i] * f[n - i]) % mod;
			if (i & 1) {
				ans = (ans + tmp) % mod;
			} else {
				ans = (ans - tmp + mod) % mod;
			}
		}
		s[n] = ans;
		cout << ans << "\n";
	}
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000000;

const ll mod = 1000000007;

ll f[N + 5];

ll power(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1LL) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1LL;
	}
	return res;
}

ll C(int n, int p) {
	ll res = f[n];
	res = (res * power(f[p], mod - 2)) % mod;
	res = (res * power(f[n - p], mod - 2)) % mod;
	return res;
}

int n, c[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = (1LL * i * f[i - 1]) % mod;
	}
	cin >> n;
	ll ans = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (i > 1) {
			ans = (ans * C(sum + c[i] - 1, c[i] - 1)) % mod;
		}
		sum += c[i];
	}
	cout << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = (1LL << 25LL) * 51LL + 1LL;

inline ll power(ll x, ll n) {
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

inline ll inv(ll n) {
	return power(n, mod - 2);
}

const int N = 100000;

ll fact[N + 5];

ll f(int n, int m) {
	ll a = fact[n];
	a = (a * m) % mod;
	a = (a * (m + 1LL)) % mod;
	a = (a * inv(2)) % mod;
	a = (a * inv(n - m + 1)) % mod;
	return a;
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cout << f(n, i);
			if (i < n) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

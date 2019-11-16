#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

const int sz = 3;

struct matrix {
	ll m[sz + 1][sz + 1];
	ll * operator [] (int x) {
		return m[x];
	}
	const ll * operator [] (const int x) const {
		return m[x];
	}
	void O() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				m[i][j] = 0;
			}
		}
	}
	void I() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				m[i][j] = (i == j);
			}
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.O();
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				if (res[i][j] >= mod) {
					res[i][j] -= mod;
				}
			}
		}
	}
	return res;
}

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

matrix power(matrix x, ll n) {
	matrix res;
	res.I();
	while (n) {
		if (n & 1LL) {
			res = res * x;
		}
		x = x * x;
		n >>= 1LL;
	}
	return res;
}

int t;
ll n;
matrix a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		n = 3LL * (n / 3LL);
		a[0][0] = 1; a[0][1] = 1; a[0][2] = 1;
		a[1][0] = 0; a[1][1] = 1; a[1][2] = 1;
		a[2][0] = 0; a[2][1] = 1; a[2][2] = 0;
		a = power(a, n);
		ll ans = (a[0][2] * power(2, mod - 2)) % mod;
		cout << ans << "\n";
	}
}

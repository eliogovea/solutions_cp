#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

const int sz = 11;

struct matrix {
	ll m[12][12];
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
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

matrix power(matrix x, int n) {
	matrix res;
	res.I();
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}

int n, a, b;
matrix M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 10; i++) {
		M[i][i] = i;
		M[i][i + 1] = 10 - i;
	}
	cin >> n >> a >> b;
	M = power(M, n);
	ll ans = 0;
	for (int i = a; i <= b; i++) {
		ans = (ans + M[0][i]) % mod;
	}
	cout << ans << "\n";
}

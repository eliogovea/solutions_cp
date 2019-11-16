#include <bits/stdc++.h>

using namespace std;

const int sz = 4;

typedef long long ll;

const ll mod = 1000007;

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

matrix  operator * (const matrix &a, const matrix &b) {
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

matrix m;

ll solve(int n) {
	m[0][0] = 0; m[0][1] = 0; m[0][2] = 1; m[0][3] = 1;
	m[1][0] = 1; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
	m[2][0] = 1; m[2][1] = 1; m[2][2] = 0; m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0; m[3][2] = 1; m[3][3] = 0;
	m = power(m, n);
    ll res = (m[1][0] + m[1][3]) % mod;
    return res;
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << solve(n) << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int MXSZ = 100;

int SZ;

typedef long long ll;

int k;
ll n;

const ll mod = 1000000007;

struct matrix {
	ll m[MXSZ][MXSZ];
	ll * operator [] (int x) {
		return m[x];
	}
	const ll * operator [] (const int x) const {
		return m[x];
	}
	void O() {
		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				m[i][j] = 0LL;
			}
		}
	}
	void I() {
		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				m[i][j] = (i == j) ? 1LL : 0LL;
			}
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.O();
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			for (int k = 0; k < SZ; k++) {
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
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

matrix M;

ll C[MXSZ][MXSZ];
ll aux[MXSZ][MXSZ];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i <= k; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	for (int i = 0; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            aux[i][j] = C[k - i][j - i];
        }
	}

	SZ = 1 + k + 1 + k + 1;
	M.O();
	M[0][0] = 1;

	for (int i = 0; i <= k; i++) {
		M[0][1 + i] = aux[0][i];
		M[0][1 + k + 1 + i] = aux[0][i];
	}

	for (int i = 1; i <= k + 1; i++) {
        for (int j = 1; j <= k + 1; j++) {
            M[i][j] = aux[i - 1][j - 1];
        }
	}

	for (int i = 1; i <= k + 1; i++) {
        for (int j = k + 2; j < SZ; j++) {
            M[i][j] = aux[i - 1][j - (k + 2)];
        }
	}

	for (int i = k + 2; i < SZ; i++) {
        for (int j = 1; j <= k + 1; j++) {
            M[i][j] = aux[i - (k + 2)][j - 1];
        }
	}

	M = power(M, n);
	cout << M[0][1 + k] << "\n";
}

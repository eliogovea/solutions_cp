#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

const int sz = 7;

inline int add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

struct matrix {
	int m[sz][sz];
	int * operator [] (int n) {
		return m[n];
	}
	const int * operator [] (const int n) const {
		return m[n];
	}
	matrix(int x) {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				m[i][j] = (i == j) ? x : 0;
			}
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return res;
}

int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) res = mul(res, x);
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

matrix power(matrix x, int n) {
	matrix res(1);
	while (n) {
		if (n & 1) res = res * x;
		x = x * x;
		n >>= 1;
	}
	return res;
}

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n) {
		matrix M(0);
		M[0][0] = 1; M[0][1] = 1; M[0][2] = 1; M[0][3] = 2; M[0][4] = 0; M[0][5] = 0; M[0][6] = 0;
		M[1][0] = 0; M[1][1] = 1; M[1][2] = 1; M[1][3] = 2; M[1][4] = 0; M[1][5] = 0; M[1][6] = 0;
		M[2][0] = 0; M[2][1] = 1; M[2][2] = 0; M[2][3] = 0; M[2][4] = 0; M[2][5] = 0; M[2][6] = 0;
		M[3][0] = 0; M[3][1] = 1; M[3][2] = 0; M[3][3] = 1; M[3][4] = 0; M[3][5] = 0; M[3][6] = 0;
		M[4][0] = 0; M[4][1] = 0; M[4][2] = 0; M[4][3] = 0; M[4][4] = 1; M[4][5] = 1; M[4][6] = 1;
		M[5][0] = 0; M[5][1] = 0; M[5][2] = 0; M[5][3] = 0; M[5][4] = 0; M[5][5] = 1; M[5][6] = 1;
		M[6][0] = 0; M[6][1] = 0; M[6][2] = 0; M[6][3] = 0; M[6][4] = 0; M[6][5] = 1; M[6][6] = 0;

		M = power(M, n - 1);

		int a = 0;
		for (int i = 0; i < sz; i++) {
			add(a, M[0][i]);
		}
		int b = 0;
		for (int i = 0; i < sz; i++) {
			add(b, M[4][i]);
		}
		b = mul(b, b);
		int ans = b;
		add(ans, MOD - a);
		ans = mul(ans, power(2, MOD - 2));
		cout << ans << "\n";
	}
}

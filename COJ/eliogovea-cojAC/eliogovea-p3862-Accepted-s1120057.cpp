// C1 - Tiling a Grid With Dominoes II

#include <bits/stdc++.h>

using namespace std;

const int H = 4;
const int S = 1 << H;
const int MOD = 1000 * 1000 * 1000 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

struct matrix {
	int v[S][S];
	matrix(int x = 0) {
		for (int i = 0; i < S; i++) {
			for (int j = 0; j < S; j++) {
				v[i][j] = 0;
			}
			v[i][i] = x;
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			for (int k = 0; k < S; k++) {
				add(res.v[i][j], mul(a.v[i][k], b.v[k][j]));
			}
		}
	}
	return res;
}

inline matrix power(matrix x, long long n) {
	matrix res(1);
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int H = 4;

	vector <bool> ok(1 << H);
	ok[(1 << H) - 1] = true;
	for (int m = (1 << H) - 2; m >= 0; m--) {
		int p = 0;
		while (m & (1 << p)) {
			p++;
		}
		if (p + 1 == H || (m & (1 << (p + 1)))) {
			ok[m] = false;
		} else {
			ok[m] = ok[m | (1 << p) | (1 << (p + 1))];
		}
	}

	matrix g(0);
	for (int m = 0; m < (1 << H); m++) {
		for (int x = 0; x < (1 << H); x++) {
			if (m & x) {
				continue;
			}
			if ((!(m & x)) && ok[m | x]) {
				add(g.v[m][x], 1);
			}
		}
	}
	long long w;
	cin >> w;
	g = power(g, w);
	cout << g.v[0][0] << "\n";
}

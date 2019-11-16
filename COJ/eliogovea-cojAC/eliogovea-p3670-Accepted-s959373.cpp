#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

const int MAXSIZE = 105;

struct matrix {
	int size;
	int values[MAXSIZE][MAXSIZE];
	matrix(int _size, int v0) {
		size = _size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				values[i][j] = 0;
			}
			values[i][i] = v0;
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size;
	assert(a.size == b.size);
	matrix res(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				add(res.values[i][j], mul(a.values[i][k], b.values[k][j]));
			}
		}
	}
	return res;
}

matrix power(matrix x, int n) {
	matrix res(x.size, 1);
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
	//freopen("dat.txt", "r", stdin);
	int n, l, m;
	cin >> n >> l >> m;
	matrix M(n, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = max(1, i - m); j <= min(n, i + m); j++) {
			M.values[i - 1][j - 1] = 1;
		}
	}
	M = power(M, l - 1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			add(ans, M.values[i][j]);
		}
	}
	cout << ans << "\n";
}

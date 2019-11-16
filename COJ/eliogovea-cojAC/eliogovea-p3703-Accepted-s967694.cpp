#include <bits/stdc++.h>

using namespace std;

const int B = 7;
const int SIZE = (1 << B) + 5;
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

struct matrix {
	int size;
	int values[SIZE][SIZE];
	matrix(int _size, int v = 0) {
		size = _size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				values[i][j] = 0;
			}
			values[i][i] = v;
		}
	}
	int * operator [] (int x) {
		return values[x];
	}
	const int * operator [] (const int x) const {
		return values[x];
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size;
	matrix res(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				add(res[i][j], mul(a[i][k], b[k][j]));
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
	int n, b;
	cin >> n >> b;
	matrix M((1 << b) + 1, 0);
	M[0][0] = 1;
	for (int d = 1; d < b; d++) {
		M[0][1 + (1 << d)] = 1;
	}
	for (int mask1 = 0; mask1 < (1 << b); mask1++) {
		for (int d = 0; d < b; d++) {
			int mask2 = mask1 ^ (1 << d);
			M[mask1 + 1][mask2 + 1]++;
		}
	}
	M = power(M, n);
	int ans = M[0][1];
	for (int d = 0; d < b; d++) {
		add(ans, M[0][1 + (1 << d)]);
	}
	add(ans, 1);
	cout << ans << "\n";
}

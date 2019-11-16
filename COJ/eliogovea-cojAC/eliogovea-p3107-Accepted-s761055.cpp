#include <iostream>

using namespace std;

const long long mod = 1000007;

struct matrix {
	int size;
	long long m[105][105];
} M;

matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.size = a.size;
	for (int i = 0; i < a.size; i++) {
    for (int j = 0; j < a.size; j++) {
      res.m[i][j] = 0;
    }
	}
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < a.size; j++) {
			for (int k = 0; k < a.size; k++) {
				res.m[i][j] += a.m[i][k] * b.m[k][j];
				res.m[i][j] %= mod;
			}
		}
	}
	return res;
}

matrix power(matrix x, int n) {
	matrix res;
	res.size = x.size;
	for (int i = 0; i < x.size; i++) {
    for (int j = 0; j < x.size; j++) {
      res.m[i][j] = (i == j);
    }
	}
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = (x * x);
		n >>= 1LL;
	}
	return res;
}

int n, m;

int main() {
  cin >> n >> m;
	//n = 1000000000; m = 100;
	M.size = m + 1;
	for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      M.m[i][j] = 0;
    }
	}
  for (int i = 1; i <= 9; i++) {
		M.m[0][1 + (i % m)]++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= 9; j++) {
			M.m[i + 1][1 + ((i + j) % m)]++;
		}
	}
	M = power(M, n);
	cout << M.m[0][1] << "\n";
}
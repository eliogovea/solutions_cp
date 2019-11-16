#include <bits/stdc++.h>

using namespace std;

struct matrix {
	double m[5][5];
	matrix(double v) {
		for (int i = 0; i < 3; i++) {
			for (int j =0 ; j < 3; j++) {
				m[i][j] = 0.0;
			}
			m[i][i] = v;
		}
	}
	double * operator [] (int x) {
		return m[x];
	}
	const double * operator [] (const int x) const {
		return m[x];
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

matrix power(matrix x, int n) {
	matrix res(1.0);
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}


double solve(int n) {
	matrix M(0.0);
	double x = 1.0;
	double y = 2.0;
	M[0][0] = 1.0; M[0][1] = cos(y); M[0][2] = sin(y);
	M[1][0] = 0.0; M[1][1] = cos(y); M[1][2] = sin(y);
	M[2][0] = 0.0; M[2][1] = -sin(y); M[2][2] = cos(y);
	M = power(M, n - 1);
	return sin(x) * M[0][0] + sin(x) * M[0][1] + cos(x) * M[0][2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(6);
	int n;
	cin >> n;
	cout << fixed << solve(n) << "\n";
}

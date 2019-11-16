// 2015 USP Try-outs
// 101047C

#include <bits/stdc++.h>

using namespace std;

const int sz = 3;

struct matrix {
	double v[sz + 1][sz + 1];
	matrix(double v0) {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				v[i][j] = 0;
			}
			v[i][i] = v0;
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res(0);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				res.v[i][j] += a.v[i][k] * b.v[k][j];
			}
		}
	}
	return res;
}

matrix power(matrix x, int n) {
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
	cout.precision(11);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		double a, l;
		int n;
		cin >> a >> l >> n;
		a = a * M_PI / 180.0;
		matrix M(0);
		M.v[0][0] = cos(a);
		M.v[0][1] = -sin(a);
		M.v[0][2] = 1.0;
		M.v[1][0] = sin(a);
		M.v[1][1] = cos(a);
		M.v[1][2] = 0.0;
		M.v[2][0] = 0.0;
		M.v[2][1] = 0.0;
		M.v[2][2] = 1.0;
		M = power(M, n);
		double x = M.v[0][2] * l;
		double y = M.v[1][2] * l;
		cout << fixed << x << " " << fixed << y << "\n";
	}
}

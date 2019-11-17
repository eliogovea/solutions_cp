// Problem: pace=1&num=1009
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, m;

const int SIZE = 3;

struct matrix {
	ll m[SIZE][SIZE];
	void O() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = 0LL;
			}
		}
	}
	void I() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = (ll)(i == j);
			}
		}
	}
};

matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.O();
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				res.m[i][j] += a.m[i][k] * b.m[k][j];
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

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n >> k;
	M.m[0][0] = 0;
	M.m[0][1] = 0;
	M.m[0][2] = k - 1LL;
	M.m[1][0] = 0;
	M.m[1][1] = 0;
	M.m[1][2] = k - 1LL;
	M.m[2][0] = 0;
	M.m[2][1] = 1;
	M.m[2][2] = k - 1LL;
	M = power(M, n);
	cout << M.m[0][1] + M.m[0][2] << "\n";
}
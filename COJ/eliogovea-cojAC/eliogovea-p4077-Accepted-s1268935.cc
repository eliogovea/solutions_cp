#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
const int SIZE = 4;

struct matrix {
	int values[SIZE][SIZE];

	matrix(int x = 0) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				values[i][j] = 0;
			}
			values[i][i] = x;
		}
	}

	int * operator [] (int row) {
		return values[row];
	}

	const int * operator [] (int row) const {
		return values[row];
	}
};


matrix operator * (const matrix & lhs, const matrix & rhs) {
	matrix result(0);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				result[i][j] += (long long)lhs[i][k] * rhs[k][j] % MOD;
				if (result[i][j] >= MOD) {
					result[i][j] -= MOD;
				}
			}
		}
	}
	return result;
}

matrix power(matrix x, int n) {
	matrix y(1);
	while (n) {
		if (n & 1) {
			y = y * x;
		}
		x = x * x;
		n >>= 1;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	matrix M(0);

	M[0][0] = a; M[0][1] = 0; M[0][2] = 0; M[0][3] = 0;
	M[1][0] = 0; M[1][1] = d; M[1][2] = 1; M[1][3] = 0;
	M[2][0] = b; M[2][1] = e; M[2][2] = 0; M[2][3] = 0;
	M[3][0] = c; M[3][1] = f; M[3][2] = 0; M[3][3] = 1;

	vector <int> v = {1, 1, 0, 1}; // [f(1), g(1), g(0), 1]

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		auto P = power(M, n - 1);

		int answer = 0;
		for (int i = 0; i < SIZE; i++) {
			answer += (long long)v[i] * P[i][0] % MOD;
			if (answer >= MOD) {
				answer -= MOD;
			}
		}

		cout << answer << "\n";
	}
}

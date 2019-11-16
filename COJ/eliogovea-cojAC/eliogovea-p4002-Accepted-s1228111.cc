#include <bits/stdc++.h>

using namespace std;

template <class T>
T power(T x, long long n) {
	T y = T(1);
	while (n) {
		if (n & 1) {
			y = y * x;
		}
		x = x * x;
		n >>= 1;
	}
	return y;
}

template <int M>
struct modInt {
	int v;

	inline void fix() {
		v %= M;
		if (v < 0) {
			v += M;
		}
	}
	
	modInt(int _v = 0) : v(_v) {
		fix();
	}

	friend modInt operator + (const modInt & lhs, const modInt & rhs) {
		return modInt(lhs.v + rhs.v);
	}

	friend modInt operator - (const modInt & lhs, const modInt & rhs) {
		return modInt(lhs.v - rhs.v);
	}

	friend modInt operator * (const modInt & lhs, const modInt & rhs) {
		return modInt((long long)lhs.v * rhs.v % M);
	}

	friend modInt operator / (const modInt & lhs, const modInt & rhs) {
		assert(rhs.v != 0);
		return lhs * power(rhs, M - 2);
	} // only for M prime

	friend bool operator == (const modInt & lhs, const modInt & rhs) {
		return (lhs.v == rhs.v);
	}
};

template <class T>
struct matrix {
	int n;
	T **values;

	matrix(int _n, T x = T(0)) : n(_n) {
		values = new T * [n];
		for (int i = 0; i < n; i++) {
			values[i] = new T[n];
			for (int j = 0; j < n; j++) {
				values[i][j] = T(0);
			}
			values[i][i] = x;
		}
	}

	T * operator [] (int row) {
		return values[row];
	}

	const T * operator [] (int row) const {
		return values[row];
	}

	friend matrix operator * (const matrix & lhs, const matrix & rhs) {
		assert(lhs.n == rhs.n);
		int n = lhs.n;
		matrix result(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					result[i][j] = result[i][j] + lhs[i][k] * rhs[k][j];
				}
			}
		}
		return result;
	}
};

template <class T>
matrix <T> power(matrix <T> x, long long n) {
	matrix <T> y(x.n, T(1));
	while (n) {
		if (n & 1) {
			y = y * x;
		}
		x = x * x;
		n >>= 1;
	}
	return y;
}

template <class T>
vector <vector <T>> pascalTriangle(int n) {
	vector <vector <T>> C(n + 1);
	for (int x = 0; x <= n; x++) {
		C[x].resize(x + 1);
		C[x][0] = C[x][x] = T(1);
		for (int y = 1; y < x; y++) {
			C[x][y] = C[x - 1][y - 1] + C[x - 1][y];
		}
	}
	return C;
}

template <class T>
T slow(int n, int k) {
	vector <T> f = {T(0), T(1)};
	for (int i = 2; i <= n; i++) {
		f.push_back(f[i - 2] + f[i - 1]);
	}

	T answer = T(0);
	for (int i = 1; i <= n; i++) {
		answer = answer + power(f[i], k);
	}

	return answer;
}

template <class T>
T fast(long long n, int k) {
	auto C = pascalTriangle <T> (k);
	matrix <T> F(k + 2);
	for (int r = 0; r <= k; r++) {
		int a = r;
		int b = k - a;
		for (int i = 0; i <= a; i++) {
			F[r][b + i] = C[a][i];
		}
	}
	F[k + 1][k] = T(1);
	F[k + 1][k + 1] = T(1);
	F = power(F, n);
	return F[k + 1][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	const int MODULO = 1000 * 1000 * 1000 + 7;
	using T = modInt <MODULO>;

	long long n;
	int k;

	cin >> n >> k;
	auto answer = fast <T> (n, k);
	cout << answer.v << "\n";
}

/*
Dado n (0 < n <= 1e18), k (0 < k <= 100), f(0) = 0, f(1) = 1, f(n) = f(n - 1) + f(n - 2)
Calcular f(1) ^ k + f(2) ^ k + ... + f(n) ^ k

Time limit: 2 segs
Memory limit: ??

Solucion O(k * k * k * log(n))
Exponenciacion de Matrices

f(n + 1) ^ k = (f(n) + f(n - 1)) ^ k = sum(comb(k, i) * (f(n) ^ i) * (f(n - 1) ^ (k - i)))

(f(n + 1) ^ a) * (f(n) ^ b) = ((f(n) + f(n - 1)))
 * */

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
				values[i][j] = 0;
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

//	cerr << "pascal triangle:\n";
//	for (auto & r : C) {
//		for (auto & c : r) {
//			cerr << c.v << " ";
//		}
//		cerr << "\n";
//	}

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

//	cerr << "F:\n";
//	for (int r = 0; r < k + 2; r++) {
//		for (int c = 0; c < k + 2; c++) {
//			cerr << F[r][c].v << " ";
//		}
//		cerr << "\n";
//	}

	F = power(F, n);

//	cerr << "F ^ n:\n";
//	for (int r = 0; r < k + 2; r++) {
//		for (int c = 0; c < k + 2; c++) {
//			cerr << F[r][c].v << " ";
//		}
//		cerr << "\n";
//	}

//	T answer = T(0);
//	vector <T> f(k + 2);
//	f[k] = 1;
//	for (int i = 0; i <= k; i++) {
//		answer = answer + F[k + 1][i] * f[i];
//	}

	return F[k + 1][k];
}


template <class T>
bool WATest(const int N = 100 * 1000, const int K = 50) {
	int n = 1 + (rand() % N);
	int k = 1 + (rand() % K);

	auto s = slow <T> (n, k);

//	cerr << "slow: " << s.v << "\n";

	auto f = fast <T> (n, k);

//	cerr << "fast: " << f.v << "\n";

	if (s.v == f.v) {
		cerr << "Passed test " << n << " " << k << " " << s.v << " " << f.v << "\n";;
		return true;
	}

	cerr << "Failed test case:\n";
	cerr << n << " " << k << "\n";
	cerr << "correct: " << s.v << "\n";
	cerr << "wrong (fast): " << f.v << "\n";

	return false;
}


template <class T>
bool TLETest() {
	long long n = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
	int k = 100;
	time_t start = clock();
	auto answer = fast <T> (n, k);
	time_t end = clock();

	cerr << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

}

void Test(int testCases = 100) {
	srand(time(nullptr));
	const int MODULO = 1000 * 1000 * 1000 + 7;
	using T = modInt <MODULO>;

	int passedTests = 0;

	cerr << "WA Tests\n";
	for (int i = 0; i < testCases; i++) {
		if (WATest <T> ()) {
			passedTests++;
		}
	}

	cerr << "Testing results:\n";
	cerr << passedTests << " passed of " << testCases << "\n";

	if (passedTests != testCases) {
		cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Somthing went wrong !!!!!!\n";
		exit(0);
	}

	cerr << "TLE Tests:\n";
	TLETest <T> ();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// Test();
	
	const int MODULO = 1000 * 1000 * 1000 + 7;
	using T = modInt <MODULO>;

	long long n;
	int k;

	cin >> n >> k;
	auto answer = fast <T> (n, k);
	cout << answer.v << "\n";
}

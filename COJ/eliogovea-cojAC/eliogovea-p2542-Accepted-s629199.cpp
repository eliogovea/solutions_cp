#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 2;
const ll mod = 1e9 + 7;

struct matrix {
	ll m[SIZE + 1][SIZE + 1];
	void nul() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = 0;
	}
	void idem() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = (i == j);
	}
	void fib() {
		nul();
		m[0][0] = m[0][1] = m[1][0] = 1;
	}
	matrix operator * (matrix &M) {
		matrix r;
		r.nul();
		for (int k = 0; k < SIZE; k++)
			for (int i = 0; i < SIZE; i++)
				for (int j = 0; j < SIZE; j++)
					r.m[i][j] = (r.m[i][j] + ((m[i][k] * M.m[k][j])) % mod) % mod;
		return r;
	}
};

matrix exp(matrix x, ll n) {
	matrix r;
	r.idem();
	while (n) {
		if (n & 1ll) r = r * x;
		x = x * x;
		n >>= 1ll;
	}
	return r;
}

int tc;
ll a, b, g, m, fg, fm;
matrix M, N;

int main() {
	std::ios::sync_with_stdio(false);
	M.fib();
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		g = __gcd(a, b);
		N = exp(M, g - 1);
		fg = N.m[0][0];
		m = (a / g) * b;
		N = exp(M, m - 1);
		fm = N.m[0][0];
		cout << fm << ' ' << fg << '\n';
	}
}

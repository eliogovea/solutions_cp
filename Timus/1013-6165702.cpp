// Problem: pace=1&num=1013
// Verdict: Accepted

#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

ll n, m, k;

inline ll mul(ll a, ll b, ll mod) {
	a %= mod;
	b %= mod;
	if (mod < int(1e9)) return a * b % mod;
	ll k = (ll)((long double)a * b / mod);
	ll res = a * b - k * mod;
	res %= mod;
	if (res < 0) res += mod;
	return res;
}

/*inline ll mul(ll a, ll b, ll mod) {
	if (mod < (int)1e9) {
		return (a * b) % mod;
	}
	ll res = 1;
	if (a > b) {
		swap(a, b);
	}
	while (b) {
		if (b & 1LL) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1LL;
	}
	return res;
}*/

const int SIZE = 3;

struct matrix {
	ll m[SIZE][SIZE];
};

inline matrix mul_mat(const matrix &a, const matrix &b) {
	matrix res;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			res.m[i][j] = 0;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				res.m[i][j] += mul(a.m[i][k], b.m[k][j], m);
				res.m[i][j] %= m;
			}
		}
	}
	return res;
}

matrix power(matrix x, ll n) {
	matrix res;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			res.m[i][j] = (i == j);
		}
	}
	while (n) {
		if (n & 1LL) {
			res = mul_mat(res, x);
		}
		x = mul_mat(x, x);
		n >>= 1LL;
	}
	return res;
}

matrix M;

int main() {
	//freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
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
	ll ans = (M.m[0][1] + M.m[0][2] + m) % m;
	cout << ans << "\n";
}

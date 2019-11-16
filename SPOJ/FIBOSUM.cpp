#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 3;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
struct matrix {
	ll m[SIZE + 1][SIZE + 1];
	ll * operator [] (int x) {
		return m[x];
	}
	const ll * operator [] (const int x) const {
		return m[x];
	}
	void O() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = 0;
			}
		}
	}
	void I() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = (i == j);
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
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				res[i][j] %= mod;
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
 
int t, n, m;
matrix a, b;
 
inline ll calc(int p) {
	if (p <= 0) {
		return 0;
	}
	if (p == 1) {
		return 1;
	}
	b = power(a, p - 1);
	return (b[0][0] + b[1][0]) % mod;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	a[0][0] = 1; a[0][1] = 0; a[0][2] = 0;
	a[1][0] = 1; a[1][1] = 1; a[1][2] = 1;
	a[2][0] = 1; a[2][1] = 1; a[2][2] = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << (calc(m) - calc(n - 1) + mod) % mod << "\n";
	}
}

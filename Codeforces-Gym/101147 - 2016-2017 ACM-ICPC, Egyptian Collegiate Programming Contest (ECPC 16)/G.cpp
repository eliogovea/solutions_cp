// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147G

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int N = 1000;

int C[N + 5][N + 5];
int f[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("galactic.in", "r", stdin);
	for (int i = 0; i <= N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1];
			add(C[i][j], C[i - 1][j]);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k > n) {
			cout << "0\n";
			continue;
		}
		f[1] = 1;
		for (int i = 2; i <= k; i++) {
			f[i] = power(i, n);
			for (int j = 1; j < i; j++) {
				add(f[i], MOD - mul(C[i][j], f[j]));
			}
		}
		cout << f[k] << "\n";
	}
}

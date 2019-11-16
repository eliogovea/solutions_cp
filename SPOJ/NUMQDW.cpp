#include <bits/stdc++.h>
 
using namespace std;
 
string s;
 
int t, n, c;
 
bool mark[10];
bool a[10][10];
 
const int mod = 4242;
 
int sz;
 
struct matrix {
	int m[70][70];
	int * operator [] (int x) {
		return m[x];
	}
	const int * operator [] (const int x) const {
		return m[x];
	}
	void O() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				m[i][j] = 0;
			}
		}
	}
	void I() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				m[i][j] = (i == j);
			}
		}
	}
};
 
matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.O();
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
	}
	return res;
}
 
matrix power(matrix x, int n) {
	matrix res;
	res.I();
	while (n) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}
 
matrix M;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
		while (t--) {
			cin >> n >> c >> s;
			if (n == 0) {
                cout << "1\n";
                continue;
			}
			int len = s.size();
			sz = 1 << c;
			M.O();
			for (int i = 0; i < c; i++) {
				mark[i] = false;
			}
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < c; j++) {
					a[i][j] = true;
				}
			}
			for (int i = 0; i < len; i++) {
				s[i] -= 'A';
				for (int j = 0; j < c; j++) {
					if (mark[j]) {
						a[j][s[i]] = false;
					}
				}
				mark[s[i]] = true;
			}
 
			for (int i = 0; i < c; i++) {
				M[0][1 << i] = 1;
			}
			for (int i = 1; i < sz; i++) {
				for (int j = 0; j < c; j++) {
					bool ok = true;
					for (int k = 0; k < c; k++) {
						if ((i & (1 << k)) && !a[k][j]) {
							ok = false;
						}
					}
					if (ok) {
						M[i][i | (1 << j)]++;
					}
				}
			}
			M = power(M, n);
			int ans = 0;
			for (int i = 1; i < sz; i++) {
				ans += M[0][i];
				if (ans > mod) {
					ans -= mod;
				}
			}
			cout << ans << "\n";
		}
}


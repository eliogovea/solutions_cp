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

inline vector <int> conv(const vector <int> &a, const vector <int> &b) {
	int n = a.size();
	vector <int> res(n);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			add(res[i + j >= n ? i + j - n : i + j], mul(a[i], b[j]));
		}
	}
	return res;
}

inline vector <int> power(vector <int> x, long long n) {
	vector <int> res(x.size()); res[0] = 1;
	while (n) {
		if (n & 1) {
			res = conv(res, x);
		}
		x = conv(x, x);
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, r;
		long long k;
		cin >> n >> k >> r;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector <int> x(n);
		x[0] = 1;
		x[1] = r;
		x = power(x, k);
		for (int i = 0; i < n; i++) {
			int v = 0;
			for (int j = 0; j < n; j++) {
				add(v, mul(a[i + j >= n ? i + j - n : i + j], x[j]));
			}
			cout << v;
			if (i + 1 < n) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

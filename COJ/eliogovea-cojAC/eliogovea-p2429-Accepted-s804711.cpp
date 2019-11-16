#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, a[N], b[N], c[N];

int bit[N];

inline void clear() {
	for (int i = 1; i <= n; i++) {
		bit[i] = 0;
	}
}

inline void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}

inline int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	while (cin >> n && n) {
		clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		int cnt = unique(b, b + n) - b;
		for (int i = 0; i < n; i++) {
			c[i] = upper_bound(b, b + cnt, a[i]) - b;
		}
		double sum = 0.0;
		for (int i = 0; i < n; i++) {
			update(c[i], 1);
			int k = 1 + (i / 2);
			int lo = 1;
			int hi = cnt;
			int pos = cnt;
			while (lo <= hi) {
				int m = (lo + hi) >> 1;
				if (query(m) >= k) {
					pos = m;
					hi = m - 1;
				} else {
					lo = m + 1;
				}
			}
			sum += b[pos - 1];
		}
		sum /= (0.0 + n);
		cout << fixed << sum << "\n";
	}
}

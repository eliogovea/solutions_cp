#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

struct fenwickTree {
	int n;
	vector <int> t;
	fenwickTree() {}
	fenwickTree(int _n) {
		n = _n;
		t = vector <int> (n + 1, 0);
	}
	void update(int p, int v) {
		assert(0 < p && p <= n);
		while (p <= n) {
			add(t[p], v);
			p += p & -p;
		}
	}
	int query(int p) {
		assert(0 <= p && p <= n);
		int res = 0;
		while (p > 0) {
			add(res, t[p]);
			p -= p & -p;
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n), c(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		b.push_back(-1);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 0; i < n; i++) {
			c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		}
		fenwickTree odd(b.size());
		fenwickTree even(b.size());
		even.update(1, 1);
		for (int i = 0; i < n; i++) {
			if (a[i] & 1) {
				even.update(c[i], odd.query(c[i] - 1));
				odd.update(c[i], even.query(c[i] - 1));
			} else {
				even.update(c[i], even.query(c[i] - 1));
				odd.update(c[i], odd.query(c[i] - 1));
			}
		}
		cout << odd.query(b.size()) << "\n";
	}
}

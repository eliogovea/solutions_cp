#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
	int n;
	vector <int> tree;
	SegmentTree() {}
	SegmentTree(int _n) : n(_n), tree(4 * n, 0) {}
	void update(int x, int l, int r, int p, int v) {
		if (p < l || r < p) {
			return;
		}
		if (l == r) {
			tree[x] = max(tree[x], v);
		} else {
			int mid = (l + r) >> 1;
			update(2 * x, l, mid, p, v);
			update(2 * x + 1, mid + 1, r, p, v);
			tree[x] = max(tree[2 * x], tree[2 * x + 1]);
		}
	}
	void update(int p, int v) {
		update(1, 1, n, p, v);
	}
	int query(int x, int l, int r, int ql, int qr) {
		if (qr < ql || r < ql || qr < l) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[x];
		}
		int mid = (l + r) >> 1;
		int q1 = query(2 * x, l, mid, ql, qr);
		int q2 = query(2 * x + 1, mid + 1, r, ql, qr);
		return max(q1, q2);
	}
	int query(int ql, int qr) {
		return query(1, 1, n, ql, qr);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		}
		vector <int> left(n);
		for (int i = 0; i < n; i++) {
			left[i] = 1;
			if (i > 0 && a[i] > a[i - 1]) {
				left[i] = left[i - 1] + 1;
			}
		}
		vector <int> right(n);
		for (int i = n - 1; i >= 0; i--) {
			right[i] = 1;
			if (i < n - 1 && a[i] < a[i + 1]) {
				right[i] = right[i + 1] + 1;
			}
		}
		SegmentTree st(b.size());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int tmp = right[i] + st.query(1, a[i]);
			ans = max(ans, tmp);
			st.update(a[i] + 1, left[i]);
		}
		cout << ans << "\n";
	}
}

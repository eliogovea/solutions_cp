#include <bits/stdc++.h>
 
using namespace std;
 
struct data {
	int m1, m2;
	data() {
		m1 = m2 = -1;
	}
	data(int a, int b) : m1(a), m2(b) {}
};
 
data merge(data a, data b) {
	if (a.m1 < b.m1) {
		swap(a, b);
	}
	int m1 = a.m1;
	int m2 = max(a.m2, max(b.m1, b.m2));
	return data(m1, m2);
}
 
const int N = 100005;
 
int n, a[N];
int q;
char t;
int x, y;
data T[4 * N];
 
void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		T[x] = data(v, -1);
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, p, v);
		update(2 * x + 1, m + 1, r, p, v);
		T[x] = merge(T[2 * x], T[2 * x + 1]);
	}
}
 
data query(int x, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return data(-1, -1);
	}
	if (l >= ql && r <= qr) {
		return T[x];
	}
	int m = (l + r) >> 1;
	data q1 = query(2 * x, l, m, ql, qr);
	data q2 = query(2 * x + 1, m + 1, r, ql, qr);
	return merge(q1, q2);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	cin >> q;
	while (q--) {
		cin >> t >> x >> y;
		if (t == 'U') {
			update(1, 1, n, x, y);
		} else {
			data ans = query(1, 1, n, x, y);
			cout << ans.m1 + ans.m2 << "\n";
		}
	}
}

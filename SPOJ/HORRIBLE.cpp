#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 100005;
 
ll t[4 * N], lazy[4 * N];
 
void build(int x, int l, int r) {
	lazy[x] = 0;
	t[x] = 0;
	if (l == r) {
        return;
	}
    int m = (l + r) >> 1;
    build(2 * x, l, m);
    build(2 * x + 1, m + 1, r);
}
 
void propagate(int x, int l, int r) {
	if (lazy[x]) {
		t[x] += 1LL * (r - l + 1LL) * lazy[x];
		if (l != r) {
			lazy[2 * x] += lazy[x];
			lazy[2 * x + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}
 
void update(int x, int l, int r, int ul, int ur, ll v) {
	propagate(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
		lazy[x] += v;
		propagate(x, l, r);
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, ul, ur, v);
		update(2 * x + 1, m + 1, r, ul, ur, v);
		t[x] = t[2 * x] + t[2 * x + 1];
	}
}
 
ll query(int x, int l, int r, int ql, int qr) {
	propagate(x, l, r);
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return t[x];
	}
	int m = (l + r) >> 1;
	ll q1 = query(2 * x, l, m, ql, qr);
	ll q2 = query(2 * x + 1, m + 1, r, ql, qr);
	return q1 + q2;
}
 
int tc, n, q;
int a, b, c, v;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		build(1, 1, n);
		while (q--) {
			cin >> a;
			if (a == 0) {
				cin >> b >> c >> v;
				update(1, 1, n, b, c, v);
			} else {
				cin >> b >> c;
				cout << query(1, 1, n, b, c) << "\n";
			}
		}
	}
}
 

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, q;

int t[4 * N];
int lazy[4 * N];

void propagate(int x, int l, int r) {
	if (lazy[x]) {
		t[x] = r - l + 1 - t[x];
		if (l != r) {
			lazy[2 * x] ^= 1;
			lazy[2 * x + 1] ^= 1;
		}
		lazy[x] = 0;
	}
}

void update(int x, int l, int r, int ul, int ur) {
	propagate(x, l, r);
	if (l > ur || r < ul) {
		return;
	}
	if (l >= ul && r <= ur) {
		lazy[x] ^= 1;
		propagate(x, l, r);
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, ul, ur);
		update(2 * x + 1, m + 1, r, ul, ur);
		t[x] = t[2 * x] + t[2 * x + 1];
	}
}

int query(int x, int l, int r, int ql, int qr) {
	propagate(x, l, r);
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return t[x];
	}
	int m = (l + r) >> 1;
	int q1 = query(2 * x, l, m, ql, qr);
	int q2 = query(2 * x + 1, m + 1, r, ql, qr);
	return q1 + q2;
}

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	while (q--) {
		cin >> a >> b >> c;
		if (b > c) {
			swap(b, c);
		}
		if (a == 0) {
			update(1, 1, n, b + 1, c + 1);
		} else {
			cout << query(1, 1, n, b + 1, c + 1) << "\n";
		}
	}
}


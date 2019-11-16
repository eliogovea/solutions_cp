#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

typedef unsigned long long ll;
const ll mod = 1000000009;

ll sum[MAXN << 2], lazy[MAXN << 2];

void build(int idx, int l, int r) {
	if (l == r) sum[idx] = 1, lazy[idx] = 1;
	else {
		int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
		lazy[idx] = 1;
		build(L, l, mid);
		build(R, mid + 1, r);
		sum[idx] = (sum[L] + sum[R]) % mod;
	}
}

void propagate(int idx, int l, int r) {
	if (lazy[idx] > 1ll) {
		sum[idx] = (sum[idx] * (lazy[idx] % mod)) % mod;
		if (l != r) {
			int L = idx << 1, R = L + 1;
			lazy[L] = (lazy[L] * (lazy[idx] % mod)) % mod;
			lazy[R] = (lazy[R] * (lazy[idx] % mod)) % mod;
		}
		lazy[idx] = 1ll;
	}
}

void update(int idx, int l, int r, int ul, int ur, ll upd) {
	propagate(idx, l, r);
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		sum[idx] = (sum[idx] * (upd % mod)) % mod;
		if (l != r) {
			int L = idx << 1, R = L + 1;
			lazy[L] = (lazy[L] * (upd % mod)) % mod;
			lazy[R] = (lazy[R] * (upd % mod)) % mod;
		}
	}
	else {
		int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
		update(L, l, mid, ul, ur, upd);
		update(R, mid + 1ll, r, ul, ur, upd);
		sum[idx] = (sum[L] + sum[R]) % mod;
	}
}

ll query(int idx, int l, int r, int ql, int qr) {
	propagate(idx, l, r);
	if (l > qr || r < ql) return 0ll;
	if (l >= ql && r <= qr) return sum[idx];
	int mid = (l + r) >> 1, L = idx << 1, R = L + 1;
	return (query(L, l, mid, ql, qr) + query(R, mid + 1, r, ql, qr)) % mod;
}

int n, m, a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	while (cin >> n >> m) {
		build(1, 1, n);
		while (m--) {
			cin >> a;
			if (a == 1) {
				cin >> b >> c;
				if (b > c) swap(b, c);
				cout << query(1, 1, n, b, c) << '\n';
			}
			else {
                if (b > c) swap(b, c);
				cin >> b >> c >> d;
				update(1, 1, n, b, c, d);
			}
		}
	}
}

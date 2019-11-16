#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100010;

int n, r;
ll k, arr[MAXN], sum[4 * MAXN], lazy[4 * MAXN];

ll build(int idx, int l, int r) {
	if (l == r) return sum[idx] = arr[l];
	int mid = (l + r) >> 1;
	return sum[idx] = build(idx << 1, l, mid)
						+ build((idx << 1) | 1, mid + 1, r);
}

void propagate(int idx, int l, int r) {
	if (lazy[idx]) {
		sum[idx] += ((ll)(r - l + 1)) * lazy[idx];
		if (l != r) {
			lazy[idx << 1] += lazy[idx];
			lazy[(idx << 1) | 1] += lazy[idx];
		}
		lazy[idx] = 0ll;
	}
}

void update(int idx, int l, int r, int ul, int ur, ll upd) {
	propagate(idx, l, r);
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		sum[idx] += ((ll)(r - l + 1)) * upd;
		if (l != r) {
			lazy[idx << 1] += upd;
			lazy[(idx << 1) | 1] += upd;
		}
	}
	else {
		int mid = (l + r) >> 1;
		update(idx << 1, l, mid, ul, ur, upd);
		update((idx << 1) | 1, mid + 1, r, ul, ur, upd);
		sum[idx] = sum[idx << 1] + sum[(idx << 1) | 1];
	}
}

ll query(int idx, int l, int r, int ql, int qr) {
	propagate(idx, l, r);
	if (l > qr || r < ql) return 0ll;
	if (l >= ql && r <= qr) return sum[idx];
	int mid = (l + r) >> 1;
	return query(idx << 1, l, mid, ql, qr) +
			query((idx << 1) | 1, mid + 1, r, ql, qr);
}

int main() {
	scanf("%d%d%lld", &n, &r, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
	build(1, 1, n);
	int A = 0, X = 0;
	for (int i = 1, a, b, c, d; i <= r; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a > b) swap(a, b);
		ll aa = query(1, 1, n, a, b);
		update(1, 1, n, a, b, k);
		if (c > d) swap(c, d);
		ll ax = query(1, 1, n, c, d);
		update(1, 1, n, c, d, k);
		if (aa > ax) A++;
		if (ax > aa) X++;
	}
	printf("Alfred: %d\nXavier: %d\n", A, X);
}

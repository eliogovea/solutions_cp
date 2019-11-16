#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;
const int Q = 1000 * 1000;
const int SIZE = 4 * N + 20 * N;

int a[N + 10], b[N + 10];

struct node {
	int val;
	int l, r;
} all[SIZE];

int size;
int root[N + 10];

int build(int l, int r) {
	int x = size++;
	all[x].val = 0;
	all[x].l = -1;
	all[x].r = -1;
	if (l != r) {
		int mid = (l + r) >> 1;
		all[x].l = build(l, mid);
		all[x].r = build(mid + 1, r);
	}
	return x;
}

int update(int x, int l, int r, int p, int v) {
	all[size] = all[x];
	x = size++;
	if (l == r) {
		all[x].val += v;
	} else {
		int mid = (l + r) >> 1;
		if (p <= mid) {
			all[x].l = update(all[x].l, l, mid, p, v);
		} else {
			all[x].r = update(all[x].r, mid + 1, r, p, v);
		}
		all[x].val = all[all[x].l].val + all[all[x].r].val;
	}
	return x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    // freopen("dat.txt", "r", stdin);
	int n, q;
	while (cin >> n >> q) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		int cnt = unique(b, b + n) - b;
		size = 0;
		root[0] = build(0, cnt - 1);
		for (int i = 0; i < n; i++) {
            a[i] = lower_bound(b, b + cnt, a[i]) - b;
		}
		for (int i = 1; i <= n; i++) {
			root[i] = update(root[i - 1], 0, cnt - 1, a[i - 1], 1);
		}
		while (q--) {
			int l, r, k;
			cin >> l >> r >> k;
			int lo = 0;
			int hi = cnt - 1;
			int pl = root[l - 1];
			int pr = root[r];
			while (lo < hi) {
				int mid = (lo + hi) >> 1;
				int cntl = all[all[pr].l].val - all[all[pl].l].val;
				if (cntl >= k) {
					hi = mid;
					pl = all[pl].l;
					pr = all[pr].l;
				} else {
					k -= cntl;
					lo = mid + 1;
					pl = all[pl].r;
					pr = all[pr].r;
				}
			}
			cout << b[lo] << "\n";
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

const int N = 4;
const int N2 = N * N;

int t;
int n, m;
string s;

int val[N + 2][N + 2][N + 2][N + 2];
int bits[(1 << N2) + 5];
int grundy[(1 << N2) + 5];
int used[(1 << N2) + 5];

const int MAX = 100 * 1000 + 10;

int arr[MAX];
int st[4 * MAX];

void build(int x, int l, int r) {
	if (l == r) {
		st[x] = arr[l];
	} else {
		int mid = (l + r) >> 1;
		build(2 * x, l, mid);
		build(2 * x + 1, mid + 1, r);
		st[x] = st[2 * x] ^ st[2 * x + 1];
	}
}

void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		st[x] = v;
	} else {
		int mid = (l + r) >> 1;
		update(2 * x, l, mid, p, v);
		update(2 * x + 1, mid + 1, r, p, v);
		st[x] = st[2 * x] ^ st[2 * x + 1];
	}
}

int query(int x, int l, int r, int ql, int qr) {
	if (qr < l || r < ql) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return st[x];
	}
	int mid = (l + r) >> 1;
	int q1 = query(2 * x, l, mid, ql, qr);
	int q2 = query(2 * x + 1, mid + 1, r, ql, qr);
	return q1 ^ q2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bits[0] = 0;
	for (int i = 1; i < (1 << N2); i++) {
		bits[i] = bits[i ^ (i & -i)] + 1;
	}

	for (int x1 = 0; x1 < N; x1++) {
		for (int x2 = x1; x2 < N; x2++) {
			for (int y1 = 0; y1 < N; y1++) {
				for (int y2 = y1; y2 < N; y2++) {
					for (int i = 0; i < N2; i++) {
						int x = i / N;
						int y = i % N;
						if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
							val[x1][x2][y1][y2] |= (1 << i);
						}
					}
				}
			}
		}
	}

	int allOnes = (1 << N2) - 1;

	grundy[0] = 0;
	for (int mask = 1; mask < (1 << N2); mask++) {
		for (int x1 = 0; x1 < N; x1++) {
			for (int x2 = x1; x2 < N; x2++) {
				for (int y1 = 0; y1 < N; y1++) {
					for (int y2 = y1; y2 < N; y2++) {
						if ((mask & val[x1][x2][y1][y2]) == val[x1][x2][y1][y2]) {
							used[grundy[mask & (allOnes ^ val[x1][x2][y1][y2])]] = mask;
						}
					}
				}
			}
		}
		grundy[mask] = 0;
        while (used[grundy[mask]] == mask) {
            grundy[mask]++;
        }
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int v = 0;
			for (int j = 0; j < N; j++) {
				cin >> s;
				for (int k = 0; k < N; k++) {
					if (s[k] == '1') {
						int pos = j * N + k;
						v |= (1 << pos);
					}
				}
			}
			arr[i] = grundy[v];
		}
		build(1, 1, n);
		while (m--) {
			int ty;
			cin >> ty;
			if (ty == 1) {
				int l, r;
				cin >> l >> r;
				cout << (query(1, 1, n, l, r) != 0 ? "Pishty" : "Lotsy") << "\n";
			} else {
				int p;
				cin >> p;
				int v = 0;
				for (int i = 0; i < N; i++) {
					cin >> s;
					for (int j = 0; j < N; j++) {
						if (s[j] == '1') {
							int pos = i * N + j;
							v |= (1 << pos);
						}
					}
					update(1, 1, n, p, grundy[v]);
				}
			}
		}
	}
}


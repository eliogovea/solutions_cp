#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int bit[N + 5];

inline void update(int p, int v) {
	while (p <= N) {
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

int solve(int k) {
	for (int i = 0; i <= N; i++) {
		bit[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		update(i, 1);
	}
	int cur = 1;
	int dir = 1;
	for (int i = 1; i < N; i++) {
		int x = query(N);
		int kk = k % x;
		if (kk == 0) {
			kk = x;
		}
		if (dir > 0) {
			int y = query(cur - 1);
			int pos = -1;
			if (x - y >= kk) {
				int lo = cur;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(mid) - y >= kk) {
						pos = mid;
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				}
			} else {
				int kkk = kk - (x - y);
				int lo = 1;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(mid) >= kkk) {
						pos = mid;
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				}
			}
			update(pos, -1);
			int next;
			if (query(pos) == query(N)) {
				int lo = 1;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(mid) >= 1) {
						next = mid;
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				}
			} else {
				int lo = pos + 1;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(mid) - query(pos) >= 1) {
						next = mid;
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				}
			}
			cur = next;
			dir = -dir;
		} else {
			int y = query(cur);
			int pos;
			if (y >= kk) {
				int lo = 1;
				int hi = cur;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(cur) - query(mid - 1) >= kk) {
						pos = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			} else {
				int kkk = kk - y;
				int lo = 1;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(N) - query(mid - 1) >= kkk) {
						pos = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			}

			update(pos, -1);
			int next;
			if (query(pos) == 0) {
				int lo = 1;
				int hi = N;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(N) - query(mid - 1) >= 1) {
						next = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			} else {
				int lo = 1;
				int hi = pos;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (query(pos) - query(mid - 1) >= 1) {
						next = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
			}
			cur = next;
			dir = -dir;
		}
	}
	return cur;
}

int ans[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		ans[i] = 1000;
	}
	for (int k = 1; k <= 1000; k++) {
		int pos = solve(k);
		if (ans[pos] > k) {
			ans[pos] = k;
		}
	}
	int n;
	while (cin >> n && n) {
		cout << ans[n] << "\n";
	}
}

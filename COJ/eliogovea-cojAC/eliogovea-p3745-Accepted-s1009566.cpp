#include <bits/stdc++.h>

using namespace std;

const int N = 1200;

int bit[N][N];

inline void update(int x, int y, int n, int v) {
	for (int xx = x; xx <= n; xx += xx & -xx) {
		for (int yy = y; yy <= n; yy += yy & -yy) {
			bit[xx][yy] += v;
		}
	}
}

inline int query(int x, int y) {
	int res = 0;
	for (int xx = x; xx > 0; xx -= xx & -xx) {
		for (int yy = y; yy > 0; yy -= yy & -yy) {
			res += bit[xx][yy];
		}
	}
	return res;
}

inline int query(int l, int b, int r, int t) {
	return query(r, t) - query(r, b - 1) - query(l - 1, t) + query(l - 1, b - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> n;
	int type;
	while (true) {
		cin >> type;
		if (type == 3) {
			break;
		}
		if (type == 1) {
			int x, y, a;
			cin >> x >> y >> a;
			update(x + 1, y + 1, n, a);
		} else if (type == 2) {
			int l, b, r, t;
			cin >> l >> b >> r >> t;
			cout << query(l + 1, b + 1, r + 1, t + 1) << "\n";
		}
	}
}

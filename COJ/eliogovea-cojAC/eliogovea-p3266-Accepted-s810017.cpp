#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a[N];

int bit[N];

void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}

int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int pts[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, 1);
	}
	int cat = 0;
	while (m--) {
		int x, y;
		cin >> x >> y;
		int cnt = query(y) - query(x - 1);
		if (cnt == 0) {
			cat ^= 1;
			continue;
		}
		int p1 = y;
		int lo = x;
		int hi = y;
		int k = query(y);
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (query(mid) >= k) {
				p1 = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		int p2 = x;
		lo = x;
		hi = y;
		k = query(n) - query(x - 1);
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (query(n) - query(mid - 1) >= k) {
				p2 = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		//cout << cat << " " << a[p2] << " " << a[p1] << "\n";
		if (p1 == p2) {
			pts[cat] += 1;
			update(p1, -1);
		} else {
			pts[cat] += __gcd(a[p1], a[p2]);
			update(p1, -1);
			update(p2, -1);
		}
		cat ^= 1;
	}
	if (pts[0] == pts[1]) {
		cout << "Draw with " << pts[0] << " points\n";
	} else {
		int p;
		if (pts[0] > pts[1]) {
			cout << "Anders ";
			p = pts[0];
		} else {
			cout << "Vinagrito ";
			p = pts[1];
		}
		cout << "wins with " << p << " points\n";
	}
}

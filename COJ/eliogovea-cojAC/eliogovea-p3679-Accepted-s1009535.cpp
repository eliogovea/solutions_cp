#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1005;

struct pt {
	int x, y;
	pt() {}
	pt(int _x, int _y) {
		x = _x; y = _y;
	}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline int cross(const pt &a, const pt &b) {
	return (LL)a.x * b.y - (LL)a.y * b.x;
}

bool is_in(int l, int r, int x) {
	if (l > r) {
		swap(l, r);
	}
	return l <= x && x <= r;
}

bool contains(const pt &a, const pt &b, const pt &p) {
	if (cross(p - a, p - b) != 0) {
		return false;
	}
	return is_in(a.x, b.x, p.x) && is_in(a.y, b.y, p.y);
}

bool inside(pt *pts, int n, pt p) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		pt a = pts[i];
		pt b = pts[(i + 1) % n];
		if (contains(a, b, p)) {
			return false;
		}
		if (a.y > b.y) {
			swap(a, b);
		}
		if (a.y == b.y || p.y <= a.y || b.y < p.y) {
			continue;
		}
		if ((LL)(b.x - a.x) * (LL)(p.y - a.y) - (LL)(b.y - a.y) * (LL)(p.x - a.x) >= 0) {
			cnt++;
		}
	}
	return (cnt & 1);
}

int t;
int a, b;
pt pa[N], pb[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			cin >> pa[i].x >> pa[i].y;
		}
		for (int i = 0; i < b; i++) {
			cin >> pb[i].x >> pb[i].y;
		}
		int ans = 0;
		for (int i = 0; i < b; i++) {
			if (inside(pa, a, pb[i])) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}

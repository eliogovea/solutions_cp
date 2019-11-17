// Problem: pace=1&num=1052
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

struct pt {
	int x, y;
	pt() {}
	pt(int xx, int yy) : x(xx), y(yy) {}
};

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int n;
pt pts[205];

map<pt, int> m;
map<pt, int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		m.clear();
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			int dx = pts[j].x - pts[i].x;
			int dy = pts[j].y - pts[i].y;
			int g = __gcd(abs(dx), abs(dy));
			dx /= g;
			dy /= g;
			if (dx < 0 || (dx == 0 && dy < 0)) {
				dx = -dx;
				dy = -dy;
			}
			m[pt(dx, dy)]++;
		}
		for (it = m.begin(); it != m.end(); it++) {
			if (1 + it->second > ans) {
				ans = 1 + it->second;
			}
		}
	}
	cout << ans << "\n";
}

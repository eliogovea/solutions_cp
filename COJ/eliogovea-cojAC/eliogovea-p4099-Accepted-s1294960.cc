#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y;

	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct line {
	int a, b, c;

	void normalize() {
		int g = __gcd(abs(a), abs(b));
		a /= g;
		b /= g;
		c /= g;

		if (a < 0 || (a == 0 && b < 0)) {
			a = -a;
			b = -b;
			c = -c;
		}
	}
};

bool operator < (const line & lhs, const line & rhs) {
	if (lhs.a != rhs.a) {
		return lhs.a < rhs.a;
	}
	if (lhs.b != rhs.b) {
		return lhs.b < rhs.b;
	}
	return lhs.c < rhs.c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector <point> pts(n);
	for (auto & P : pts) {
		cin >> P.x >> P.y;
	}

	map <line, int> cnt;

	map <int, int> rt;
	for (int i = 1; i <= n; i++) {
		rt[i * (i - 1) / 2] = i;
	}

	long long answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = pts[j].x - pts[i].x;
			int dy = pts[j].y - pts[i].y;

			line r;
			r.a = dy;
			r.b = -dx;
			r.c = -(r.a * pts[i].x + r.b * pts[i].y);
			r.normalize();

			cnt[r]++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			int dx = pts[j].x - pts[i].x;
			int dy = pts[j].y - pts[i].y;

			int rdx = -dy;
			int rdy = dx;

			line l;
			l.a = rdy;
			l.b = -rdx;
			l.c = -(l.a * pts[i].x + l.b * pts[i].y);
			l.normalize();

			if (cnt.find(l) != cnt.end()) {
				answer += rt[cnt[l]] - 1;
			}
		}
	}

	cout << answer / 2LL << "\n";
}

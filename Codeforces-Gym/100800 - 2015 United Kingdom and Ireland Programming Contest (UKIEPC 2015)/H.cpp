// 2015 United Kingdom and Ireland Programming Contest (UKIEPC 2015)
// 100800H

#include <bits/stdc++.h>

using namespace std;

struct pt {
	long long x, y;
	pt(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

long long cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

void solve() {
	int n;
	cin >> n;
	vector <pt> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	vector <int> s(n);
	int top = 0;
	vector <int> l(n);
	for (int i = 0; i < n; i++) {
		while (top > 1 && cross(p[i] - p[s[top - 2]], p[s[top - 1]] - p[s[top - 2]]) <= 0) {
			top--;
		}
		if (top > 0) {
			l[i] = s[top - 1];
		}
		s[top++] = i;
	}
	top = 0;
	vector <int> r(n);
	for (int i = n - 1; i >= 0; i--) {
		while (top > 1 && cross(p[i] - p[s[top - 2]], p[s[top - 1]] - p[s[top - 2]]) >= 0) {
			top--;
		}
		if (top > 0) {
			r[i] = s[top - 1];
		}
		s[top++] = i;
	}
	for (int i = 0; i < n; i++) {
        //cerr << i << " " << l[i] << " " << r[i] << "\n";
		double angle = M_PI;
		if (i > 0) {
			if (p[i].y < p[l[i]].y) {
				double dx = p[i].x - p[l[i]].x;
				double dy = p[l[i]].y - p[i].y;
				angle -= atan(dy / dx);
			}
		}
		if (i < n - 1) {
			if (p[i].y < p[r[i]].y) {
				double dx = p[r[i]].x - p[i].x;
				double dy = p[r[i]].y - p[i].y;
				angle -= atan(dy / dx);
			}
		}
		double ans = angle * 12.0 / M_PI;
		cout << fixed << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cout.precision(15);
	solve();
}

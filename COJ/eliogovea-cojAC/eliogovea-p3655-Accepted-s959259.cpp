#include <bits/stdc++.h>

using namespace std;

struct pt {
	double x, y;
};

bool operator < (const pt &a, const pt &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

bool cmp_x(const pt &a, const pt &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

inline double dist(const pt &a, const pt &b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

const int N = 100005;

int t, n;
pt pts[N];
set <pt> box;
set <pt>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}
		sort(pts, pts + n, cmp_x);
		bool ok = true;
		for (int i = 1; i < n; i++) {
			if (pts[i].x == pts[i - 1].x && pts[i].y == pts[i - 1].y) {
				ok = false;
			}
 		}
		if (!ok) {
			cout << "0\n";
			continue;
		}
		double ans = dist(pts[0], pts[1]);
		box.clear();
		box.insert(pts[0]);
		for (int i = 1, last = 0; i < n; i++) {
			while (last < i && (double)pts[i].x - (double)pts[last].x > ans) {
				box.erase(pts[last++]);
			}
			//cout << "---- " << pts[i].x << " " << pts[i].y << "\n";
			set <pt>::iterator lo = box.lower_bound((pt) {-1e9, pts[i].y - ans});
			set <pt>::iterator hi = box.upper_bound((pt) {1e9, pts[i].y + ans + 1});
			for (it = lo; it != hi; it++) {
				//cout << " "  << it->x << " " << it->y << "\n";
				ans = min(ans, dist(pts[i], *it));
			}
			box.insert(pts[i]);
		}
		//cout << "\n";
		long long val = ans;
		//cout << ans << "\n";
		cout << val << "\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, d, sol = 1 << 29;

struct pt {
	int x, y;
	pt() {}
	pt(int a, int b) : x(a), y(b) {}
	bool operator < (const pt &P) const {
		if (x != P.x) return x < P.x;
		return y < P.y;
	}
} pts[MAXN];

struct cmp_y {
	bool operator () (const pt &a, const pt &b) {
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	}
};

set<pt, cmp_y> S;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> pts[i].x >> pts[i].y;
	sort(pts, pts + n);
    int tail = 0;
	for (int i = 0; i <= n; i++) {
		while (S.size() > 1 && abs(S.rbegin()->y - S.begin()->y) >= d) {
			sol = min(sol, pts[i - 1].x - pts[tail].x);
			S.erase(S.find(pts[tail]));
			tail++;
		}
		if (i < n) S.insert(pts[i]);
	}
	if (sol == 1 << 29) cout << "-1\n";
	else cout << sol << '\n';
}

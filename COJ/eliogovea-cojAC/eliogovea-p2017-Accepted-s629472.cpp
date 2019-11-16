#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const double eps = 1e-9;

struct pt {
	double x, y;
	pt() {}
	pt(double xx, double yy) : x(xx), y(yy) {}
} pts[MAXN], Q;

double cross(pt &a, pt &b, pt &c) {
	return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int tc, n, q;

int main() {
	ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> pts[i].x >> pts[i].y;
		cin >> q;
		while (q--) {
			cin >> Q.x >> Q.y;
			int sol = 0;
			for (int i = 0, j = n - 1; i < n; j = i++)
				sol += (cross(pts[i], pts[j], Q) > eps);
			cout << sol << '\n';
		}
		cout << '\n';
	}
}

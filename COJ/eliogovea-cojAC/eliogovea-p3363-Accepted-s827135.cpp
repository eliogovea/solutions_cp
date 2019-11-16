#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	int t;
	cin >> t;
	while (t--) {
		double xa, ya, xb, yb, dist;
		cin >> xa >> ya >> xb >> yb >> dist;
		double dx, dy;
		dx = xb - xa;
		dy = yb - ya;
		double l = sqrt(dx * dx + dy * dy);
		dx /= l;
		dy /= l;
		double tmpdx = dx;
		double tmpdy = dy;
		dx = -tmpdy;
		dy = tmpdx;
		double xc = (xa + xb) / 2.0;
		double yc = (ya + yb) / 2.0;
		double ansx = xc + dist * dx;
		double ansy = yc + dist * dy;
		cout << fixed << ansx << " ";
		cout << fixed << ansy << "\n";
	}
}

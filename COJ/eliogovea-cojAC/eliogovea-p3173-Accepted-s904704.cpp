#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x1, x2, y1, y2;
	double	d;
	cin >> x1 >> y1 >> x2 >> y2 >> d;
	int y = min(y1, y2);
	int ans = 0;
	for (int x = -500; x <= 500; x++) {
		for (int y = -500; y <= 500; y++) {
			double d1 = sqrt((double)(x - x1) * (x - x1) + (double)(y - y1) * (y - y1));
			double d2 = sqrt((double)(x - x2) * (x - x2) + (double)(y - y2) * (y - y2));
			if (d1 + d2 + EPS < d) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

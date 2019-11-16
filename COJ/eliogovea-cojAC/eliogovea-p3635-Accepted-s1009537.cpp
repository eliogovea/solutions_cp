#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	double x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		double dx = abs(x1 - x2);
		double dy = abs(y1 - y2);
		double ans = (dx * dx + dy * dy) / 6.0;
		cout << fixed << ans << "\n";
	}
}

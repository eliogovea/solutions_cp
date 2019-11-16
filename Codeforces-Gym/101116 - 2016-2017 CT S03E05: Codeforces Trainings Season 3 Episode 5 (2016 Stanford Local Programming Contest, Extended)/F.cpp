// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116F

#include <bits/stdc++.h>

using namespace std;

const double R = 6371.0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		double a1, a2, b1, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		a1 = a1 * M_PI / 180.0;
		a2 = a2 * M_PI / 180.0;
		b1 = b1 * M_PI / 180.0;
		b2 = b2 * M_PI / 180.0;
		double deltaA = min(abs(a1 - a2), 2.0 * M_PI - abs(a1 - a2));
		double deltaB = min(abs(b1 - b2), 2.0 * M_PI - abs(b1 - b2));
		double z1 = R * sin(a1);
		double x1 = R * cos(a1) * cos(b1);
		double y1 = R * cos(a1) * sin(b1);
		double z2 = R * sin(a2);
		double x2 = R * cos(a2) * cos(b2);
		double y2 = R * cos(a2) * sin(b2);
		double r = sqrt(R * R - z1 * z1);
		double dist1 = R * deltaA + r * deltaB;
		double dist2 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
		double angle = asin(dist2 / (2.0 * R));
		dist2 = R * 2.0 * angle;
		cout << fixed << dist2 << " " << fixed << dist1 << "\n";
	}
}

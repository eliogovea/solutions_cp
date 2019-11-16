#include <bits/stdc++.h>

using namespace std;

struct pt {
	double x, y;
	pt() {}
	pt(double _x, double _y) : x(_x), y(_y) {}
};

pt operator + (const pt &a, const pt &b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

pt operator * (const pt &a, const double k) {
	return pt(a.x * k, a.y * k);
}

inline double dist(const pt &a, const pt &b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int n;
pt p[150];
double f[150];
double g[150][150];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	n += 2;
	cin >> p[0].x >> p[0].y;
	cin >> p[1].x >> p[1].y;
	for (int i = 2; i < n; i++) {
		cin >> p[i].x >> p[i].y >> f[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				g[i][j] = min(dist(p[i], p[j]), dist(p[i] + (p[j] - p[i]) * (f[i] / dist(p[i], p[j])), p[j]));
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	cout.precision(2);
	cout << fixed << g[0][1] << "\n";
}

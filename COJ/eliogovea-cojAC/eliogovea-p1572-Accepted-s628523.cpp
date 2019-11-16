#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const int MAXN = 20;

void mini(double a, double &b) {
	if (a < b) b = a;
}

struct pt {
	double x, y;
	pt() {}
	pt(double xx, double yy) : x(xx), y(yy) {}
};

double cross(pt &a, pt &b, pt &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(pt &a, pt &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

pt center(pt &A, pt &B, pt &C) {
	double a1 = 2.0 * (B.x - C.x);
	double b1 = 2.0 * (B.y - C.y);
	double c1 = C.x * C.x + C.y * C.y - B.x * B.x - B.y * B.y;
	double a2 = 2.0 * (A.x - C.x);
	double b2 = 2.0 * (A.y - C.y);
	double c2 = C.x * C.x + C.y * C.y - A.x * A.x - A.y * A.y;
	return pt((c2 * b1 - c1 * b2) / (b2 * a1 - a2 * b1), (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2));
}

int tc, n;
double x, y;
vector<pt> pts, centers;
double dp[1 << MAXN][MAXN];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		pts.clear();
		centers.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			pts.push_back(pt(x, y));
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				for (int k = 0; k < j; k++)
					if (fabs(cross(pts[i], pts[j], pts[k])) > eps)
						centers.push_back(center(pts[i], pts[j], pts[k]));
		int cc = centers.size();
		for (int mask = 0; mask < (1 << cc); mask++)
			for (int i = 0; i < cc; i++)
				dp[mask][i] = 1e9;
		for (int i = 0; i < cc; i++)
			dp[1 << i][i] = 0;
		for (int mask = 1; mask < (1 << cc); mask++)
			for (int i = 0; i < cc; i++)
				if (mask & (1 << i))
					for (int j = 0; j < cc; j++)
						if (!(mask & (1 << j)))
							mini(dp[mask][i] + dist(centers[i], centers[j]), dp[mask | (1 << j)][j]);
		double sol = 1e9;
		//cout << cc << endl;
		for (int i = 0; i < cc; i++)
			mini(dp[(1 << cc) - 1][i], sol);
		printf("%.4lf\n", cc ? sol : 0);
	}
}

// Problem: pace=1&num=1020
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n;
double r;
double x[105], y[105];
double ans = 0.0;

inline double dist(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		int next = (i + 1) % n;
		ans += dist(i, next);
	}
	ans += 2.0 * M_PI * (double)r;
	cout.precision(2);
	cout << fixed << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const double INF = 1e8;
int n;
double t[N], v[N];

inline double calc(double tt) {
	double maxD = v[0] * (tt - t[0]);
	double minD = maxD;
	for (int i = 1; i < n; i++) {
		minD = min(minD, v[i] * (tt - t[i]));
		maxD = max(maxD, v[i] * (tt - t[i]));
	}
	return maxD - minD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cout.precision(10);
	while (cin >> n && n) {
		double lo = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> t[i] >> v[i];
			lo = max(lo, t[i]);
		}
		double hi = INF;
		double d, a, b;
		for (int it = 0; it < 250; it++) {
			d = (hi - lo) / 3.0;
			a = lo + d;
			b = hi - d;
			if (calc(a) > calc(b)) {
				lo = a;
			} else {
				hi = b;
			}
		}
		double ans = calc((lo + hi) / 2.0);
		cout << fixed << ans << "\n";
	}
}

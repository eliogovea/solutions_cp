// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150F

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	//freopen("dat.txt", "r", stdin);
	const int MaxDiff = 10000;
	const double INF = 1e13;
	int n;
	while (cin >> n && n) {
		vector <int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		double b;
		cin >> b;
		int r;
		double v, e, f;
		cin >> r >> v >> e >> f;
		vector <double> te(MaxDiff + 5, 0.0);
		vector <double> tf(MaxDiff + 5, 0.0);
		for (int i = 1; i <= MaxDiff; i++) {
			te[i] = te[i - 1] + 1.0 / (v - e * ((double)(i - 1.0)));
			tf[i] = tf[i - 1] + 1.0 / (v - f * ((double)(r - (i - 1.0))));
		}
		vector <double> dp(n + 1, INF);
		dp[0] = 0.0;
		for (int i = 0; i < n; i++) {
			double t = dp[i];
			if (i != 0) {
				t += b;
			}
			for (int j = i + 1; j <= n; j++) {
				int d = a[j] - a[i];
				double tt = t;
				if (d <= r) {
					tt += tf[d];
				} else {
					tt += tf[r] + te[d - r];
				}
				dp[j] = min(dp[j], tt);
			}
		}
		cout << fixed << dp[n] << "\n";
	}
}

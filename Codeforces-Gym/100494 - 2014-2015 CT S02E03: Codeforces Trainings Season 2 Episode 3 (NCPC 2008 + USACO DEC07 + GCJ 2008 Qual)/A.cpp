// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494A

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

const double INF = 1e14;

int n;
double l, w;
double p[2 * N];

double dp[N][N];

double solve(int ll, int rr) {
	if (ll == 0 && rr == 0) {
		return 0.0;
	}
	if (dp[ll][rr] > -0.5) {
		return dp[ll][rr];
	}
	double res = INF;
	if (ll > 0) {
		double delta = l / (double)(n / 2 - 1);
		double y = delta * (double)(ll - 1.0);
		res = min(res, solve(ll - 1, rr) + abs(p[ll + rr - 1] - y));
	}
	if (rr > 0) {
		double delta = l / (double)(n / 2 - 1);
		double y = delta * (double)(rr - 1.0);
		res = min(res, solve(ll, rr - 1) + sqrt((p[ll + rr - 1] - y) * (p[ll + rr - 1] - y) + w * w));
	}
	dp[ll][rr] = res;
	//cout << ll << " " << rr << " " << res << "\n";
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> w;
	for (int i = 0; i < n; i++) {
        cin >> p[i];
	}
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= n / 2; j++) {
			dp[i][j] = -1.0;
		}
	}
	sort(p, p + n);
	cout.precision(15);
	cout << fixed << solve(n / 2, n / 2) << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;

int n;
double p[2 * N];
double sp[2 * N];
bool solved[2 * N][2 * N][5];
double dp[2 * N][2 * N][5];

double solve(int l, int r, int x) {
	if (solved[l][r][x]) {
		return dp[l][r][x];
	}

	if (l == 0 && r == 2 * n - 1) {
		return 0;
	}

	solved[l][r][x] = true;
	double res = -1.0;

	if (x == 0) {
		if (l - 1 >= 0) {
			double ee = 1.0 - (sp[r + 1] - sp[l]) + solve(l - 1, r, 0);
			if (res < -0.5 || ee < res) {
				res = ee;
			}
		}

		if (r + 1 < 2 * n) {
			double ee = ((double)r - (double)l + 2.0) * (1.0 - (sp[r + 1] - sp[l])) + solve(l, r + 1, 1);
			if (res < -0.5 || ee < res) {
				res = ee;
			}
		}
	}

	if (x == 1) {
		if (l - 1 >= 0) {
			double ee = ((double)r - (double)l + 2.0) * (1.0 - (sp[r + 1] - sp[l])) + solve(l - 1, r, 0);
			if (res < -0.5 || ee < res) {
				res = ee;
			}
		}

		if (r + 1 < 2 * n) {
			double ee = 1.0 - (sp[r + 1] - sp[l]) + solve(l, r + 1, 1);
			if (res < -0.5 || ee < res) {
				res = ee;
			}
		}
		
	}

	// cerr << l << " " << r << " " << x << " " << res << "\n";

	dp[l][r][x] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		cin >> p[i];
		sp[i + 1] = sp[i] + p[i];
	}

	double res = 1.0 + min(solve(n - 1, n - 1, 0), solve(n, n, 1));

	cout.precision(6);
	cout << fixed << res << "\n";

}

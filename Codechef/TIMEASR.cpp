#include <bits/stdc++.h>

using namespace std;

const double eps = 1.0 / 120.0 + 1e-10;

int t;
double a;

pair<double, pair<int, int> > ans[100 * 100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sz = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 60; j++) {
			double m = 6.0 * j;
			double h = 30.0 * i + j / 2.0;
			ans[sz].first = fabs(m - h);
			//while (ans[sz].first >= 360.0) ans[sz].first -= 360.0;
			if (ans[sz].first >= 180.0) ans[sz].first = 360.0 - ans[sz].first;
			ans[sz].second.first = i;
			ans[sz].second.second = j;
			//cout << ans[sz].first << " " << ans[sz].second.first << " " << ans[sz].second.second << "\n";
			sz++;
		}
	}

	sort(ans, ans + sz);
	cin >> t;
	while (t--) {
		cin >> a;
		int l = 0;
		int r = sz - 1;
		int p = r;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (ans[m].first + eps >= a) {
				p = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		for (int i = p; i < sz && fabs(ans[i].first - a) <= eps; i++) {
			if (ans[i].second.first < 10) cout << "0";
			cout << ans[i].second.first << ":";
			if (ans[i].second.second < 10) cout << "0";
			cout << ans[i].second.second << "\n";
		}
	}
}


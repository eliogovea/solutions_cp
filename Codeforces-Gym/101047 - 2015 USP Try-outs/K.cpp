// 2015 USP Try-outs
// 101047K

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

int t;
int n;
double a[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		bool ok = false;
		double ans;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				int lo = j + 1;
				int hi = n - 1;
				int pos = -1;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					if (a[mid] <= a[i] + a[j] + EPS) {
						pos = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				if (pos != -1) {
					double s = (a[i] + a[j] + a[pos]) * 0.5;
					double area = sqrt(s * (s - a[i]) * (s - a[j]) * (s - a[pos]));
					if (!ok || area < ans) {
						ok = true;
						ans = area;
					}
					s = (a[i] + a[j] + a[j + 1]) * 0.5;
					area = sqrt(s * (s - a[i]) * (s - a[j]) * (s - a[j + 1]));
					if (!ok || area < ans) {
                        ok = true;
                        ans = area;
					}
				}
			}
		}
		if (!ok) {
			cout << "-1\n";
		} else {
			cout << fixed << ans << "\n";
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	int t;
	cin >> t;
	while (t--) {
		int n;
		double l;
		cin >> n >> l;
		vector <int> x(n), v(n);
		int id = 1;
		double tt = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			if (x[i] > x[id]) {
				id = i;
			}
			if (v[i] > 0) {
				double tmp = (l + l - (double)x[i]) / (double)v[i];
				tt = max(tt, tmp);
			} else {
				double tmp = (double)x[i] / (double)abs(v[i]);
				tt = max(tt, tmp);
			}
		}
		cout << fixed << tt << " " << id + 1 << "\n";
	}
}

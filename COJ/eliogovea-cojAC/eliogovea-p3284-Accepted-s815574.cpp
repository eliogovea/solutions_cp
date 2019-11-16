#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int t, n;
double E[N + 5];
double ans[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	for (int i = 1; i <= N; i++) {
		ans[i] = -1.0;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		if (ans[n] < 0.0) {
			E[n] = 0;
			for (int i = n - 1; i >= 0; i--) {
				int k = min(10, n - i);
				E[i] = 1.0;
				for (int j = 1; j <= k; j++) {
					E[i] += E[i + j] / (double)k;
				}
			}
			ans[n] = E[0];
		}
		cout << fixed << ans[n] << "\n";
	}
}

#include <bits/stdc++.h>

using namespace std;

int n, p, m;
int a[20];
int dp[1 << 17];
int o[1 << 17];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = p + 1;
		o[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		o[1 << i] = a[i];
	}
	cin >> m;
	int pr, c, x;
	while (m--) {
		cin >> pr;
		cin >> c;
		int mask = 0;
		for (int i = 0; i < c; i++) {
			cin >> x;
			x--;
			mask |= (1 << x);
		}
		if (o[mask] == -1 || pr < o[mask]) {
			o[mask] = pr;
		}
	}
	int y = 0;
	int z = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		int smask = mask;
		while (smask > 0) {
			if (o[smask] != -1) {
				dp[mask] = min(dp[mask], dp[mask ^ smask] + o[smask]);
			}
			smask = (smask - 1) & mask;
		}
		if (dp[mask] > p) {
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				cnt++;
			}
		}
		//cout << mask << " " << cnt << " " << dp[mask] << "\n";
		if (cnt > y || (cnt == y && dp[mask] < z)) {
            //cout << "in " << y << " " << z << "\n";
			y = cnt;
			z = dp[mask];
            //cout << "out " << y << " " << z << "\n";
		}
	}
	cout << y << " " << z << "\n";
}

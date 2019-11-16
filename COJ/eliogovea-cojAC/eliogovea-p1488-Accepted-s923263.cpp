#include <bits/stdc++.h>

using namespace std;

int x, y, d, n, dx[25], dy[25];

map <pair <int, int>, bool> dp;

bool solve(int xx, int yy) {
	if (xx * xx + yy * yy > d * d) {
		return true;
	}
	map <pair <int, int>, bool>::iterator it = dp.find(make_pair(xx, yy));
	if (it != dp.end()) {
		return it->second;
	}
	for (int i = 0; i < n; i++) {
		if (!solve(xx + dx[i], yy + dy[i])) {
			dp[make_pair(xx, yy)] = true;
			return true;
		}
	}
	dp[make_pair(xx, yy)] = false;
	return false;
}

const string ans[] = {"Ollie", "Stan"};

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int c = 0; c < 3; c++) {
		cin >> x >> y >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> dx[i] >> dy[i];
		}
		dp.clear();
		cout << ans[solve(x, y)] << " wins\n";
	}
}

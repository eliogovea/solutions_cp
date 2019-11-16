// Problem: pace=1&num=1110
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;

int power(int x, int n, int m) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % m;
		}
		x = (x * x) % m;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> y;
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		if (y == power(i, n, m)) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) {
			cout << " ";
		}
	}
	if (ans.size() == 0) {
        cout << "-1";
	}
	cout << "\n";
}

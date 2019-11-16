#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	LL k;
	cin >> n >> k;
	LL lo = 1;
	LL hi = n;
	LL x = lo;
	while (lo <= hi) {
		LL mid = (lo + hi) / 2LL;
		if (mid * (mid - 1LL) / 2LL <= k) {
			x = mid;
			lo = mid + 1LL;
		} else {
			hi = mid - 1LL;
		}
	}
	LL d = k - x * (x - 1LL) / 2LL;
	vector <int> ans;
	int y = x;
	while (ans.size() < x - d) {
		ans.push_back(y);
		y--;
	}
	ans.push_back(x + 1);
	while (y >= 1) {
		ans.push_back(y);
		y--;
	}
	x += 2;
	while (x <= n) {
		ans.push_back(x);
		x++;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i + 1 < n) {
			cout << " ";
		}
	}
	cout << "\n";
}

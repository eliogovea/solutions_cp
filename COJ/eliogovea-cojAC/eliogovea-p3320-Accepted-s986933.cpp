#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	while (cin >> n >> m) {
		if (n == 0LL && m == 0LL) {
			break;
		}
		long long cur = 1;
		long long ans = (m + n) * (m - n + 1LL) / 2LL;
		while (cur * cur <= m) {
			if (cur * cur >= n) {
				ans -= cur * cur;
			}
			cur++;
		}
		cout << ans << "\n";
	}
}

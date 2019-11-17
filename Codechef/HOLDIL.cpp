#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF = 1000000;

int t;
LL s;

inline LL f(LL n) {
	return (n * (n + 1LL) * (2LL * n + 1)) / 6LL;
}

LL solve(LL s) {
	LL lo = 0;
	LL hi = 1e6;
	LL res = hi;
	while (lo <= hi) {
		LL mid = (lo + hi) >> 1;
		if (f(mid) <= s) {
			res = mid;
			lo = mid + 1;
		} else {
		    hi = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		cout << solve(s) << "\n";
	}
}


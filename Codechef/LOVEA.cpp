#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL get(LL x) {
	LL lo = 0;
	LL hi = 1e9;
	LL res = 1e9;
	while (lo <= hi) {
		LL mid = (lo + hi) >> 1;
		if (mid * mid <= x) {
			res = mid;
			lo = mid + 1;
		} else {
            hi = mid - 1;
		}
	}
	return res;
}

LL solve(LL l, LL r) {
	return get(r) - get(l - 1);
}

int t;
LL l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << solve(l, r) << "\n";
	}
}


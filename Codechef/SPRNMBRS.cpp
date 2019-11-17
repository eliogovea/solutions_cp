#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int t;
LL l, r;

int calc(LL n) {
	if (n == 0) {
		return 0;
	}
	int res = 1;
	for (LL pow2 = 2; pow2 <= n; pow2 *= 2LL) {
		for (LL pow3 = 1; pow3 <= n / pow2; pow3 *= 3LL) {
			res++;
		}
	}
	return res;
}

int solve(LL l, LL r) {
	return calc(r) - calc(l - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << solve(l, r) << "\n";
	}
}


#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

LL calc(LL n, bool par) {
	LL res = 0;
	for (int i = 62; i > 0; i--) {
		if (n & (1LL << i)) {
			return (1LL << (i - 1)) + calc(n - (1LL << i), !par);
		}
	}
	if (n == 1) {
		return 1;
	}
	return par;
}

LL find(LL n) {
    if (n == 1) {
        return 0;
    }
	LL lo = 0;
	LL hi = 2e18;
	LL res = hi;
	while (lo <= hi) {
		LL mid = (lo + hi) >> 1LL;
		if (calc(mid, true) >= n) {
			res = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	LL n;
	while (cin >> n && n) {
		cout << find(n) << "\n";
	}
}

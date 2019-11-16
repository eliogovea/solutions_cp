#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

typedef long long LL;

LL find(LL x) {
	if (x == 0LL) return 0LL;
	LL k = 0LL;
	while (true) {
		LL tmp = (1LL) << k;
		tmp *= tmp;
		if (tmp > x) break;
		k++;
	}
	k--;
	LL tmp = (1LL) << k;
	LL ret = (x - tmp * tmp + 1LL) * tmp;
	for (k--; k >= 0LL; k--) {
		tmp = (1LL) << (3LL * k);
		tmp *= 3LL;
		ret += tmp;
	}
	return ret;
}
int main() {//freopen("dat.in","r",stdin);
	LL tc;
	cin >> tc;
	while (tc--) {
		LL lo, hi;
		cin >> lo >> hi;
		if (lo > hi) swap(lo, hi);
		cout << find(hi) - find(lo - 1LL) << "\n";
	}
}


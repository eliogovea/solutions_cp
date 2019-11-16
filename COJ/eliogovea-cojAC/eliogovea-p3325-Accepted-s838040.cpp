#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL calc(LL n, bool par) {
	LL res = 0;
	for (int i = 31; i > 0; i--) {
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
	LL lo = 0;
	LL hi = 1LL << 31LL;
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

map<pair<LL, bool>, LL> M;
map<pair<LL, bool>, LL>::iterator it;

LL sum(LL n, bool par) {
	it = M.find(make_pair(n, par));
	if (it != M.end()) {
		return it->second;
	}
	for (int i = 31; i >= 0; i--) {
		if (n & (1LL << i)) {
			LL ans = M[make_pair(n, par)] = (1LL << i) * calc(n - (1LL << i), !par) + sum(n - (1LL << i), !par) + sum((1LL << i) - 1, par);
			return ans;
		}
	}
	M[make_pair(n, par)] = 0;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int n;
	while (cin >> n) {
		cout << sum(find(n), true) << "\n";
	}
}

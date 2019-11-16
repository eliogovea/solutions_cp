#include <iostream>

using namespace std;

typedef unsigned long long ull;

const ull c = 6e9;
const ull inf = 16e18;

ull n;

inline ull f(ull x) {
	ull a, b;
	a = x;
	b = x + 1LL;
	if (a & 1LL) b >>= 1LL;
	else a >>= 1LL;
	return a * b;
}

bool solve() {
	ull lo = 0, hi = c, mid, v;
	while (lo + 1LL < hi) {
		mid = (lo + hi + 1LL) >> 1LL;
		v = f(mid);
		if (v == n) return true;
		if (v < n) lo = mid;
		else hi = mid;
	}
	return false;
}

int main() {
	while (cin >> n && n) {
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}

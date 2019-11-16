#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100005;

typedef long long ll;

ll n, m, t[MAXN], sol;

ll f(ll x) {
	ll r = 0;
	for (int i = 0; i < n; i++)
		r += (x / t[i]);
	return r;
}

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	ll lo = 0, hi = 1e18, mid, v;
	while (lo + 1 < hi) {
		mid = (lo + hi + 1) >> 1;
		v = f(mid);
		if (v >= m) sol = hi = mid;
		else lo = mid;
	}
	cout << sol << '\n';
}

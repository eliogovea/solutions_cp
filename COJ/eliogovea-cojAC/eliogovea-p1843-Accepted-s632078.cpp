#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1000000000;

vector<ll> t, c, v;
vector<ll>::iterator it;

int main() {
    ios::sync_with_stdio(false);
	for (ll i = 1; ; i++) {
		ll tr = i * (i + 1) / 2 + 1;
		if (tr > MAX) break;
		t.push_back(tr);
	}
	for (ll i = 1; ; i++) {
		ll sc = i * i;
		if (sc > MAX) break;
		c.push_back(sc);
	}
	for (it = t.begin(); it != t.end(); it++)
		if (binary_search(c.begin(), c.end(), *it))
			v.push_back(*it);
	ll a, b, cas = 0;
	ios::sync_with_stdio(false);
	while (cin >> a >> b && (a | b))
		cout  << "Case " << ++cas << ": " << upper_bound(v.begin(), v.end(), b - 1ll) - lower_bound(v.begin(), v.end(), a + 1ll) << '\n';
}

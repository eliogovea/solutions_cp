#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1000000000;

vector<ll> v;

void build(ll i) {
	if (i >= inf) return;
	v.push_back(i);
	for (ll j = (i % 10ll) + 1ll; j < 10ll; j++)
		build(10ll * i + j);
}

int tc;
ll a, b;

int main() {
	build(0);
	sort(v.begin(), v.end());
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << upper_bound(v.begin(), v.end(), b) -
                lower_bound(v.begin(), v.end(), a)
             << '\n';
	}
}

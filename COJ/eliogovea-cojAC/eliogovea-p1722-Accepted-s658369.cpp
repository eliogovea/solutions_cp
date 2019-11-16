#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll MAXN = 1000050, mod = 1000007;

bool criba[MAXN + 5];
vector<ll> primos;

ll tc, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = true;
	primos.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i]) primos.push_back(i);
	cin >> tc;
	while (tc--) {
		cin >> n;
		ll sol = 1;
		ll cnt = 0;
		for (int i = 0; primos[i] <= n; i++) {
			ll p = primos[i];
			cnt++;
			ll tmp = 0;
			for (ll j = p; j <= n; j *= p)
        tmp = (tmp + n / j) % mod;
			sol = (sol * ((tmp * (tmp + 1) / 2) % mod)) % mod;
		}
		cout << cnt << " " << sol << "\n";
	}
}

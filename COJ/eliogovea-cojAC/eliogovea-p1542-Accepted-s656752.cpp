#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll power(ll x, ll n) {
	ll r = 1;
	while (n) {
		if (n & 1ll) r = (r * x) % mod;
		x = (x * x) % mod;
		n >>= 1ll;
	}
	return r;
}

ll tc, x, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << power(2, n - 1) << "\n";
	}
}

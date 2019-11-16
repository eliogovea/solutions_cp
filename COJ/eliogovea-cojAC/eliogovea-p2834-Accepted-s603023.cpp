#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100000;
const ll mod = 1000000007;

ll n;
bool criba[MAXN + 10];
vector<ll> p, f;

int main() {

	for (ll i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (ll j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	for (int i = 2; i <= MAXN; i++) if (!criba[i]) p.push_back(i);
	while (scanf("%lld", &n) == 1) {
		f.clear();
		ll v = n;
		for (vector<ll>::iterator it = p.begin(); (*it) * (*it) <= n; it++)
			if (n % *it == 0) {
				f.push_back(*it);
				while (n % *it == 0) n /= *it;
			}
		if (n > 1ll) f.push_back(n);

		int s = f.size();
		ll sol = 0ll;

		//for (int i = 0; i < s; i++) printf("%d ", f[i]);
		//printf("\n");

		for (int mask = 1; mask < (1 << s); mask++) {
			int cont = 0;
			ll prod = 1;
			for (int i = 0; i < s; i++) if (mask & (1 << i)) cont++, prod *= f[i];
			//printf("%d\n", cont);
			if (cont & 1) sol = (sol + (prod * (v / prod) * ((v / prod) - 1) / 2) % mod) % mod;
			else sol = (sol - (prod * (v / prod) * ((v / prod) - 1) / 2) % mod + mod) % mod;
		}
		printf("%lld\n", sol);

	}
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 10000000;

bool criba[MAXN + 5];
vector<ll> p;

void Criba() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	p.push_back(2);
	for (ll i = 3; i <= MAXN; i += 2)
		if (!criba[i]) p.push_back(i);
}

ll NDiv(ll n) {
	ll ret = 1, cont;
	for (ll i = 0; p[i] * p[i] <= n; i++)
		if (n % p[i] == 0ll) {
			cont = 0ll;
			while (n % p[i] == 0ll) cont++, n /= p[i];
			ret *= (cont + 1);
		}
	if (n > 1ll) ret *= 2ll;
	return ret;
}

ll solve(int n) {
	ll ret = 1ll, cont, cd = NDiv(n);
	for (ll i = 0ll; p[i] * p[i] <= n; i++)
		if (n % p[i] == 0ll) {
			cont = 0ll;
			while (n % p[i] == 0ll) n /= p[i], cont++;
			ret *= ((cont * cd) >> 1ll) + 1ll;
		}
	if (n > 1ll) ret *= (cd >> 1ll) + 1ll;
	return ret;
}

int n;

int main() {
    Criba();
	while (scanf("%lld", &n) && n)
        printf("%lld\n", solve(n));
}

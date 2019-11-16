#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 10000;

bool criba[MAXN + 5];
vector<ll> p;
void Criba() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	p.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i])
			p.push_back(i);
}

ll n, k;

int main() {
	ios::sync_with_stdio(false);
	Criba();
	while (cin >> n >> k && (n | k)) {
		ll m = k;
		ll sol = LLONG_MAX;
		for (int i = 0; p[i] * p[i] <= m; i++)
			if (m % p[i] == 0) {
				ll cont = 0;
				while (m % p[i] == 0) {
					cont++;
					m /= p[i];
				}
				ll a = p[i], x = 0;
				while (true) {
					x += n / a;
					if (a > n / p[i]) break;
					a *= p[i];
				}
				sol = min(sol, x / cont);
			}
        if (m > 1) {
            ll a = m, x = 0;
            while (true) {
                x += n / a;
                if (a > n / m) break;
                a *= m;
            }
            sol = min(sol, x);
        }
		cout << sol << '\n';
	}
}

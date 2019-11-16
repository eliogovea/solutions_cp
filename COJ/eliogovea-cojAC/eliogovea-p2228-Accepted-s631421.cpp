#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 31622780;

bool criba[MAXN + 5];
vector<long long> p;
void Criba() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	p.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i]) p.push_back(i);
}

long long tc, n, sol;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	Criba();
	cin >> tc;
	while (tc--) {
		cin >> n;
		sol = 1ll;
		for (int i = 0; p[i] * p[i] <= n; i++)
			if (n % p[i] == 0) {
				sol *= p[i];
				while (n % p[i] == 0) n /= p[i];
			}
		if (n > 1ll) sol *= n;
		cout << sol << '\n';
	}
}

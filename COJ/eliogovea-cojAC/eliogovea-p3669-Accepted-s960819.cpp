#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	ULL n;
	cin >> n;
	ULL p = 2;
	ULL ans =0;
	while (p <= n) {
		ULL res = n % p;
		if (res == p - 1LL) {
			ULL val = (n / p);
			ans += p * (val * (val + 1ULL) / 2ULL);
		} else {
			ULL val = (n / p) - 1;
			ans += p * (val * (val + 1ULL) / 2ULL) + (res + 1ULL) * (n / p);
		}
		p *= 2ULL;
	}
	cout << ans << "\n";
}

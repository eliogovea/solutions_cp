#include <cstdio>

typedef long long ll;

const int MAXN = 1000000;
const ll mod = 1000000007;

int n;
ll a[MAXN + 10];

int main() {
	for (ll i = 1ll; i <= (ll)MAXN; i++)
		a[i] = (a[i - 1] + (i * i) % mod) % mod;
	while (scanf("%d", &n) == 1) printf("%lld\n", a[n]);
}

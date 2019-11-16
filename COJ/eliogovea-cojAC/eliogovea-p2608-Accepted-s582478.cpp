#include <cstdio>

typedef long long ll;

ll f(ll n)
{
    ll res = (n & 1ll);
	for (ll i = 1ll, aux = res; ll(1ll << i) <= n; i++)
		if (n & ll(1ll << i))
            res += i * (1ll << ll(i - 1ll)) + aux + 1ll,
            aux |= ll(1ll << i);
	return res;
}
ll a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", f(b) - f(a - 1ll));
}

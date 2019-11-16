#include <iostream>
using namespace std;

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
    //while (cin >> a) cout << f(a) << endl;
    cin >> a >> b;
    cout << f(b) - f(a - 1ll) << endl;
}

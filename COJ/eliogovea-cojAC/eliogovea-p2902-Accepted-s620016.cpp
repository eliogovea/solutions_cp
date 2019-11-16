#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = (ll)1e9;

ll exp(ll x, ll n) {
    ll ret = 1ll;
    while (n) {
        if (n & 1ll) ret = (ret * x) % mod;
        n >>= 1ll;
        x = (x * x) % mod;
    }
    return ret;
}

string n;
ll k, a, sol;

int main() {
    while (cin >> n >> k) {
        a = (exp(2ll, k) - 2ll + mod) % mod;
        sol = 1ll;
        reverse(n.begin(), n.end());
        for (int i = 0; n[i]; i++) {
            sol = (sol * exp(a, ll(n[i] - '0'))) % mod;
            a = exp(a, 10ll);
        }
        cout << sol << "\n";
    }
}

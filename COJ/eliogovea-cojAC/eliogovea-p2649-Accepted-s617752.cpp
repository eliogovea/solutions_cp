#include <iostream>
using namespace std;

typedef long long ll;

const ll mod = 1000003;

ll exp(ll a, ll b) {
    ll r = 1ll;
    while (b) {
        if (b & 1ll) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return r;
}

ll solve(int n) {
    ll x = (exp(4ll, n + 1ll) - 1ll + mod) % mod;
    ll y = exp(3ll, mod - 2ll);
    return (x * y) % mod;
}

int tc;
ll n;

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sf scanf
#define pf printf
#define MAXN 1000100
//#define ll long long


typedef unsigned long long ll;
const ll mod = 1000000007;

ll exp(ll x, ll n) {
    ll r = 1ll;
    x %= mod;
    while (n) {
        if (n & 1ll) r = (r * x) % mod;
        x = (x * x) % mod;
        n >>= 1ll;
    }
    return r;
}

ll tc, n, k;

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        k %= mod;
        cout << exp(k + 1ll, n) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll len = 30;

ll n, mask, sol;
char str[35];
map<ll, ll> m;

int main() {
    scanf("%lld", &n);
    for (ll i = 0ll; i < n; i++) {
        scanf("%s", str);
        mask = 0ll;
        for (ll j = 0ll; j < len; j++)
            if (str[j] == 'T')
                mask |= (1ll << j);
        for (ll j = 0ll; j < len; j++) {
            if ( m.find( mask ^ (1ll << j) ) != m.end() )
                sol += m[mask ^ (1ll << j)];
            for (ll k = j + 1; k < len; k++)
                if (m.find(mask ^ (1ll << j) ^ (1ll << k)) != m.end())
                    sol += m[mask ^ (1ll << j) ^ (1ll << k)];
        }
        sol += m[mask]++;
    }
    printf("%lld\n", sol);
}

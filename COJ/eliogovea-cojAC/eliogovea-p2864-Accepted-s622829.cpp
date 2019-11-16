#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

typedef long long ll;

ll n, idx['z' + 5], sol;
char str[MAXN];

map<ll, ll> m;

int main() {
    for (char c = 'A'; c <= 'Z'; c++)
        idx[c] = c - 'A';
    for (char c = 'a'; c <= 'z'; c++)
        idx[c] = c - 'a' + 'Z' - 'A' + 1ll;
    scanf("%lld%s", &n, str);
    m[0] = 1;

    ll mask = 0ll;
    for (int i = 0; str[i]; i++) {
        //printf("%d %lld\n", i, sol);
        mask ^= (1ll << idx[str[i]]);
        for (char c = 'A'; c <= 'Z'; c++)
            if ( m.find( mask ^ (1ll << idx[c]) ) != m.end() )
            sol += m[ mask ^ (1ll << idx[c]) ];
        for (char c = 'a'; c <= 'z'; c++)
            if ( m.find( mask ^ (1ll << idx[c]) ) != m.end() )
            sol += m[ mask ^ (1ll << idx[c]) ];
        if (m.find(mask) != m.end()) {
            sol += m[mask];
            m[mask]++;
        }
        else
            m[mask] = 1ll;
    }
    printf("%lld\n", sol);
}

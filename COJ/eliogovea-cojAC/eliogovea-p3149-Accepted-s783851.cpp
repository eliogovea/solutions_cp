#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1LL) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1LL;
    }
    return res;
}

int get(int n, int p) {
    ll pot = p;
    ll res = 0;
    while (pot <= n) {
        res += n / pot;
        pot *= p;
    }
    return res;
}

const int N = 50000;

int t, n;

bool criba[N + 5];
vector<int> p;

ll f[N + 5];

int main() {
    for (int i = 2; i * i <= N; i++) {
        if (!criba[i]) {
            for (int j = i * i; j <= N; j += i) {
                criba[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!criba[i]) {
            p.push_back(i);
        }
    }
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * (long long)i) % mod;
    }

    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 1;
        for (int i = 0; p[i] <= n && i < p.size(); i++) {
            ll e = get(n, p[i]);
            //cout << p[i] << " " << e << "\n";
            ll a = (power(p[i], e + 1) - 1 + mod) % mod;
            ll b = power(p[i] - 1, mod - 2);
            a = (a * b) % mod;
            ans = (ans * a) % mod;
        }
        ans = (ans - f[n] + mod) % mod;
        cout << ans << "\n";
    }
}
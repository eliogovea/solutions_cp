#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;

inline void add(int & a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

inline int mul(int a, int b) {
    return (long long)a * b % M;
}

inline int power(int x, int n) {
    int y = 1;
    while (n) {
        if (n & 1) {
            y = mul(y, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return y;
}

inline int inverse(int x) {
    return power(x, M - 2);
}

const int N = 1000 * 1000 + 10;

int fact[N];
int invFact[N];

int phi[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    vector <int> cnt(k);

    int n = 0;
    int g = 0;
    int o = 0;

    for (auto & x : cnt) {
        cin >> x;
        n += x;
        g = __gcd(g, x);
        if (x & 1) {
            o++;
        }
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    invFact[n] = power(fact[n], M - 2);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = mul(invFact[i + 1], i + 1);
        assert(mul(fact[i], invFact[i]) == 1);
    }

    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    // rotaciones

    int rot = 0;
    for (int d = 1; d <= n; d++) {
        if (n % d == 0) {
            int c = n / d;
            if (g % c == 0) {
                int t = fact[d];
                for (auto x : cnt) {
                    t = mul(t, invFact[x / c]);
                }
                t = mul(t, phi[c]);
                add(rot, t);
            }
        }
    }

    // reflexiones

    int ref = 0;
    if (n & 1) {
        if (o == 1) {
            int t = 0;
            for (auto x : cnt) {
                t += x / 2;
            }
            t = fact[t];
            for (auto x : cnt) {
                t = mul(t, invFact[x / 2]);
            }
            t = mul(t, n);
            add(ref, t);
        }
    } else {
        if (o == 2) {
            int t = 0;
            for (auto x : cnt) {
                t += x / 2;
            }
            t = mul(fact[t], 2);
            for (auto x : cnt) {
                t = mul(t, invFact[x / 2]);
            }
            t = mul(t, n / 2);
            add(ref, t);
        } else if (o == 0) {
            int t = 0;
            {
                int t1 = 0;
                int v = fact[(n - 2) / 2];
                for (auto x : cnt) {
                    v = mul(v, invFact[x / 2]);
                }
                for (auto x : cnt) {
                    int w = mul(v, mul(fact[x / 2], invFact[(x - 2) / 2]));
                    add(t1, w);
                }

                t1 = mul(t1, n / 2);

                add(t, t1);

            }

            {
                int t2 = fact[n / 2];
                for (auto x : cnt) {
                    t2 = mul(t2, invFact[x / 2]);
                }

                t2 = mul(t2, n / 2);
                
                add(t, t2);
            }

            add(ref, t);
        }
    }

    int tot = rot + ref;
    if (tot >= M) {
        tot -= M;
    }

    tot = mul(tot, inverse(2 * n));

    cout << tot << "\n";

}

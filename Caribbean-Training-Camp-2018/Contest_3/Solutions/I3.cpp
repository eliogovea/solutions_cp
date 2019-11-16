#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 50 * 50 + 10;

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

int n;
int a[N];
int fact[N];
int invFact[N];

int cp[N];
int f[N];
int g[N];

inline int comb(int a, int b) {
    if (a < b || a < 0 || b < 0) {
        return 0;
    }
    return mul(fact[a], mul(invFact[b], invFact[a - b]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

     // freopen("dat.txt", "r", stdin);

     fact[0] = 1;
     invFact[0] = 1;
     for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = power(fact[i], M - 2);
     }

    cin >> n;

    int t = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t += a[i];
    }

    for (int i = 1; i <= t; i++) {
        int x = 1;
        for (int j = 0; j < n; j++) {
            x = mul(x, comb(a[j] + i - 1, i - 1));
        }
        cp[i] = x;
        // cerr << i << " " << x << "\n";
    }

    for (int i = 1; i <= t; i++) {
        f[i] = cp[i];
        for (int j = 1; j < i; j++) {
            if (j & 1) {
                add(f[i], M - mul(comb(i, j), cp[i - j]));
            } else {
                add(f[i], mul(comb(i, j), cp[i - j]));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= t; i++) {
        add(ans, f[i]);
    }

    cout << ans << "\n";
}

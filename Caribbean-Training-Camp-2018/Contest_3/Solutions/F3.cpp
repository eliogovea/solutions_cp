#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;

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
int a[N + 10];
int f[N + 10];
int c[N + 10];

int mu[N + 10];
bool sieve[N + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            c[i] += f[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        mu[i] = 1;
    }

    sieve[1] = true;
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) {
            for (int j = i + i; j <= N; j += i) {
                sieve[j] = true;
            }
            if ((long long)i * i <= N) {
                for (int j = i * i; j <= N; j += i * i) {
                    mu[j] = 0;
                }
            }
            for (int j = i; j <= N; j += i) {
                mu[j] = -mu[j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (mu[i] == -1) {
            mu[i] = M - 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        c[i] = power(2, c[i]);
        add(c[i], M - 1);
    }

    int ans = 0;

    for (int g = 1; g <= N; g++) {
        int t = 0;
        for (int x = g; x <= N; x += g) {
            add(t, mul(c[x], mu[x / g]));
        }
        add(ans, mul(g, t));
    }

    cout << ans << "\n";
}

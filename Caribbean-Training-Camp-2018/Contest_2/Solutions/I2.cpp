#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res -= res / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}

int cnt(int n) {
    int res = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int e = 0;
            while (n % i == 0) {
                e++;
                n /= i;
            }
            res *= (e + 1);
        }
    }
    if (n > 1) {
        res *= 2;
    }
    return res;
}

LL sum(int n) {
    LL res = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            LL p = 1;
            while (n % i == 0) {
                p *= (LL)i;
                n /= i;
            }
            res *= ((LL)p * i - 1LL) / (i - 1LL);
        }
    }
    if (n > 1) {
        res *= (1LL + (LL)n);
    }
    return res;
}

inline int power(int x, int n, int m) {
    int y = 1;
    while (n) {
        if (n & 1) {
            y = (long long)y * x % m;
        }
        x = (long long)x * x % m;
        n >>= 1;
    }
    return y;
}

int inverse(int x, int n) {
    if (__gcd(x, n) != 1) {
        return -1;
    }
    int p = phi(n);
    int ix = power(x, p - 1, n);
    assert(((long long)x * ix % n) == 1);
    return power(x, p - 1, n);
}

LL egcd(LL a, LL b, LL & x, LL & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL g = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

bool diophantine(LL a, LL b, LL c, LL & x, LL & y, LL & g) {
    g = egcd(a, b, x, y);
    if (c % g != 0) {
        return false;
    }
    x *= c / g;
    y *= c / g;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    const int M = 2007;
    const int PHIM = phi(M);

    int n;
    cin >> n;

    vector <int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector <int> cnt(n + 1);
    vector <int> last(n + 1);
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
                last[j] = i;
            }
        }
    }

    vector <int> e(n + 1);

    vector <int> g(n + 1);

    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 1) {
            int x = i;
            while (x > 0) {
                e[i]++;
                x /= last[i];
            }
        }
    }

    g[1] = inverse(f[1], M);
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 1) {
            // cerr << i << " " << "case 1\n";
            int s = 0;
            int a = i;
            int b = 1;
            while (a > 1) {
                s += (f[a] * g[b]) % M;
                s %= M;
                a /= last[i];
                b *= last[i];
            }
            s = M - s;
            s = s * power(f[1], PHIM - 1, M) % M;
            g[i] = s;
        } else {
            // cerr << i << " " << "case 2\n";
            int p = last[i];
            int v = i;
            while (last[v] == last[i]) {
                v /= last[i];
            }
            g[i] = g[v] * g[i / v] % M;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << g[i];
        if (i + 1 <= n) {
            cout << " ";
        }
    }
    cout << "\n";

/*
    LL a, b, c;
    cin >> a >> b >> c;
    LL x, y, g;
    bool ok = diophantine(b, a, c, y, x, g);
    g = abs(g);
    if (!ok) {
        cout << "Impossible\n";
    } else {
        cerr << x << " " << y << "\n";
        LL q1 = (c / g) * (b / g);
        LL q2 = (c / g) * (a / g);

        cerr << q1 << " " << q2 << "\n";

        if (x < 0) {
            LL t = (-x + q1 - 1LL) / q1;
            x += t * q1;
            y -= t * q2;
        } else if (x > 0) {
            LL t = x / q1;
            x -= t * q1;
            y += t * q2;
        }

        cout << x << " " << y << "\n";
    }
*/
}

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


    int n, e, c;
    cin >> n >> e >> c;
    int d = inverse(e, phi(n));
    cout << power(c, d, n) << "\n";
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

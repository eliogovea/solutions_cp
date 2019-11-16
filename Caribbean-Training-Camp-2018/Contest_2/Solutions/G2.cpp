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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << inverse(n, m) << "\n";
}

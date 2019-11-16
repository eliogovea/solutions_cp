#include <iostream>

using namespace std;

inline int phi(int n) {
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

inline int power(int x, int n, int p) {
    x %= p;
    int y = 1;
    while (n) {
        if (n & 1) {
            y = y * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;
        int res = 0;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                res += power(n, d - 1, p) * (phi(n / d) % p) % p;
                if (res >= p) {
                    res -= p;
                }
                if (d != n / d) {
                    res += power(n, n / d - 1, p) * (phi(d) % p) % p;
                    if (res >= p) {
                        res -= p;
                    }
                }
            }
        }
        cout << res << "\n";
    }
}

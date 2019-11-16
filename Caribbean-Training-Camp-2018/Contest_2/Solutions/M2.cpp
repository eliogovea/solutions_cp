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

LL gcd(LL a, LL b, vector <pair <int, LL>> & ans) {
    if (b == 0) {
        return a;
    }
    LL k = a / b;
    if (k > 0) {
        ans.push_back({0, -k});
    } else if (k < 0) {
        ans.push_back({0, k});
    }
    ans.push_back({1, 0});
    return gcd(b, a % b, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <pair <int, LL>> v1, v2;

    LL g1 = gcd(a, b, v2);
    LL g2 = gcd(c, d, v1);

    if (g1 != g2) {
        cout << "No solution.\n";
    } else {
        cout << v1.size() + v2.size() << "\n";
        int aa = a;
        int bb = b;
        for (auto x : v2) {
            if (x.first == 1) {
                cout << "swap(a, b)\n";
                swap(aa, bb);
            } else {
                if (x.second < 0) {
                    cout << "a -= " << -x.second << " * b\n";
                    aa -= -x.second * bb;
                } else {
                    cout << "a += " << x.second << " * b\n";
                    aa += x.second * bb;
                }
            }
        }
        reverse(v1.begin(), v1.end());
        for (auto x : v1) {
            if (x.first == 1) {
                cout << "swap(a, b)\n";
                swap(aa, bb);
            } else {
                aa += -x.second * bb;
                if (x.second < 0) {
                    cout << "a += " << -x.second << " * b\n";
                } else {
                    cout << "a -= " << x.second << " * b\n";
                }
            }
        }
        assert(aa == c && bb == d);
    }

/*
    LL a, b; cin >> a >> b;

    if (a % b == 0) {
        cout << a / b << " 0\n";
    } else {
        LL q = a / b;
        if (q < 0) {
            q--;
        }
        LL r = a - q * b;
        if (b > 0 && r < 0 || b < 0 && r > 0) {
            cout << "Impossible\n";
        } else {
            cout << q << " " << r << "\n";
        }
    }
*/
/*
    LL q = a / b;
    LL r = a - q * b;

    if( q < 0 ){
        q--;
    }

    if( a != r + q * b || (b < 0 && r > 0) || (b > 0 && r < 0) ){
        cout << "Impossible\n";
        //cerr << q << ' ' << r << '\n';
    }
    else{
        cout << q << ' ' << r << '\n';
    }
*/
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

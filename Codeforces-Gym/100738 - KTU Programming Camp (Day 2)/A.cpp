// KTU Programming Camp (Day 2)
// 100738A

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

inline double getw(double a, double b, double ang) {
    return a * cos(ang) + b * sin(ang);
}

inline double geth(double a, double b, double ang) {
    return a * sin(ang) + b * cos(ang);
}

bool solve(double a, double b, double c, double d) {
    double angmx = atan((double)b / a);
    double mx = getw(a, b, angmx);
    if (a <= c && c <= mx) {
        double lo = 0;
        double hi = angmx;
        for (int i = 0; i < 400; i++) {
            double mid = (lo + hi) / 2.0;
            if (getw(a, b, mid) < c) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        double ang = (lo + hi) / 2.0;
        if (geth(a, b, ang) <= d) {
            return true;
        }
    }
    if (b <= c && c <= mx) {
        double lo = angmx;
        double hi = M_PI / 2.0;
        for (int i = 0; i < 400; i++) {
            double mid = (lo + hi) / 2.0;
            if (getw(a, b, mid) < c) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        double ang = (lo + hi) / 2.0;
        if (geth(a, b, ang) <= d) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) {
        swap(a, b);
    }
    if (c < d) {
        swap(c, d);
    }
    if (c <= a && d <= b) {
        cout << "YES\n";
        return 0;
    }
    if (a <= c && b <= d) {
        cout << "YES\n";
        return 0;
    }
    if (solve(a, b, c, d) || solve(a, b, d, c) || solve(b, a, c, d) || solve(c, d, a, b) || solve(c, d, b, a) || solve(d, c, a, b) || solve(d, c, b, a)) {
        cout << "YES\n";
        return 0;
    }
    cout <<  "NO\n";
}

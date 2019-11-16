#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

inline double getW(double a, double b, double angle) {
    return b * cos(angle) + a * sin(angle);
}

inline double getH(double a, double b, double angle) {
    return b * sin(angle) + a * cos(angle);
}

inline bool ok(double a, double b, double c, double d) {
    double A = atan((double)a / b);
    double W = getW(a, b, A);
    if (W <= d + EPS) {
        return (min(a, b) <= c + EPS);
    }
    if (b <= d + EPS && d <= W + EPS) {
        double lo = 0.0;
        double hi = A;
        for (int it = 0; it < 400; it++) {
            double mid = (lo + hi) / 2.0;
            if (getW(a, b, mid) < d) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        double angle = (lo + hi) / 2.0;
        if (getH(a, b, angle) <= c + EPS) {
            return true;
        }
    }
    if (a <= d + EPS && d <= W + EPS) {
        double lo = A;
        double hi = M_PI / 2.0;
        for (int it = 0; it < 400; it++) {
            double mid = (lo + hi) / 2.0;
            if (getW(a, b, mid) > d) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        double angle = (lo + hi) / 2.0;
        if (getH(a, b, angle) <= c + EPS) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ans = (ok(a, b, c, d) || ok(b, a, c, d) || ok(a, b, d, c) || ok(b, a, d, c));
    cout << (ans ? "Possible" : "Impossible") << "\n";
}

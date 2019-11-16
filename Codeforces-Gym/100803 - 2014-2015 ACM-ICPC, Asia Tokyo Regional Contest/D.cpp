// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803D

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int n, d, b;
double p[10005], h[10005];

inline bool check(double x, double angle) {
    double v = sqrt(x / sin(2.0 * angle));
    double aa = -1.0 / (2.0 * v * v * cos(angle) * cos(angle));
    double bb = tan(angle);
    for (int i = 0; i < n; i++) {
        double cnt = (int)(p[i] / x);
        double xx = p[i] - cnt * x;
        double yy = aa * xx * xx + bb * xx;
        if (yy < h[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cout.precision(10);
    cin >> d >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> h[i];
    }
    double ans;
    for (int i = 0; i <= b; i++) {
        double x = d / ((double)(i + 1));
        double lo = M_PI / 4.0;
        double hi = M_PI / 2.0;
        for (int it = 0; it < 200; it++) {
            double mid = (lo + hi) / 2.0;
            if (check(x, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        double angle = (lo + hi) / 2.0;
        double vel = sqrt(x / sin(2.0 * angle));
        if (i == 0 || vel < ans) {
            ans = vel;
        }
    }
    cout.precision(10);
    cout << fixed << ans << "\n";
}

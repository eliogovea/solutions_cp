// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801A

#include <bits/stdc++.h>

using namespace std;

double h, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    cin >> h >> w;
    double lo = 0;
    double hi = min(h, w);
    for (int i = 0; i < 200; i++) {
        double mid = (lo + hi) / 2.0;
        double x = 3.0 * mid;
        double y = mid;
        bool ok = false;
        if ((x <= w && y <= h) || (x <= h) && y <= w) {
            ok = true;
        }
        x = 2.0 * mid;
        y = 2.0 * mid;
        if ((x <= w && y <= h) || (x <= h) && y <= w) {
            ok = true;
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    double ans = (lo + hi) / 2.0;
    cout.precision(10);
    cout << fixed << ans << "\n";
}

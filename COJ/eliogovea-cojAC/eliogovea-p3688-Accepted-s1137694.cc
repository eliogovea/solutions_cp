#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(12);

    int t;
    cin >> t;

    while (t--) {
        long double d1, d2;
        cin >> d1 >> d2;
        double lo = max(d1, d2);
        double hi = 1e10;

        for (int it = 0; it < 1000; it++) {
            double l = (lo + hi) / 2.0;
            double f = l * l - 2.0 * sqrt(l * l - d1 * d1) * sqrt(l * l - d2 * d2) + 2.0 * d1 * d2;
            if (f > 0.0) {
                lo = l;
            } else {
                hi = l;
            }
        }

        double l = (lo + hi) / 2.0;
        double ans = sqrt(3.0) * l * l / 4.0;
        cout << fixed << ans << "\n";
    }
}

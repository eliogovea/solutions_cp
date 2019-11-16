// KTU Programming Camp (Day 2)
// 100738K

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double eps = 1e-7;

LL a, b, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> p;
    LL lo = 1;
    LL hi = 1e18;
    LL res = hi;
    for (int it = 0; it <= 500; it++) {
        LL mid = (lo + hi) / 2.0;
        double val = (double)a * pow(mid, 1.0 / 3.0) + (double)b * pow(mid, 1.0 / 2.0);
        //cout << mid << " " << val << "\n";
        if ((LL)(val + eps) >= p) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << "\n";
}

// KTU Programming Camp (Day 3)
// 100739I

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double eps = 1e-7;

long double a, b, r;

inline long double get_r(int n) {
    return r / sin(M_PI / (long double)n) - r;
}

int solve() {
    int lo = 3;
    int hi = 1e8;
    int x = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (get_r(mid) + eps >= a) {
            x = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (x == -1) {
        return 0;
    }
    lo = 3;
    hi = 1e8;
    int y = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (get_r(mid) <= b + eps) {
            y = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (y == -1) {
        return 0;
    }
    //cout << get_r(x) << " " << get_r(y) << "\n";
    //cout << x << " " << y << "\n";
    return y - x + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> r;
    cout << solve() << "\n";
}

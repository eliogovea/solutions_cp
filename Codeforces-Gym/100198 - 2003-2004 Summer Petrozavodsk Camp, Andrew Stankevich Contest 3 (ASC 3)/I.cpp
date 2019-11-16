// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 3 (ASC 3)
// 100198I

#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

double r1, r2;

inline double f(double x) {
    return sqrt((r1 * r1 - x * x) * (r2 * r2 - x * x));
}

inline double ff(double x) {
    return x * x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("twocyl.in", "r", stdin);
    freopen("twocyl.out", "w", stdout);
    cin >> r1 >> r2;
    if (r1 > r2) swap(r1, r2);
    double h = r1 / N;
    double s = 0.0;
    for (int i = 0; i <= N; i++) {
        double x = h * i;
        s += f(x) * ((i == 0 || i == N) ? 1 : ((i & 1) == 0) ? 2 : 4);
    }
    s *= 8.0 * h / 3.0;
    cout.precision(4);
    cout << fixed << s << "\n";
}
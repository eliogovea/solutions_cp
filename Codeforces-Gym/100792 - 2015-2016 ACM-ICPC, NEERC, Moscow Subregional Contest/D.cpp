// 2015-2016 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100792D

#include <bits/stdc++.h>

using namespace std;

long long b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    double h1, h2, t1, t2;
    cin >> h1 >> t1 >> h2 >> t2;
    double a = h1 - h2;
    double b = 2.0 * (h2 * t1 - h1 * t2);
    double c = h1 * t2 * t2 - h2 * t1 * t1;
    double d = b * b - 4.0 * a * c;
    double ans1 = (-b - sqrt(d)) / (2.0 * a);
    double ans2 = (-b + sqrt(d)) / (2.0 * a);
    cout.precision(10);
    if (ans1 > 0 && ans2 > 0) {
        cout << fixed << min(ans1, ans2) << "\n";
    } else if (ans1 > 0) {
        cout << fixed << ans1 << "\n";
    } else {
        cout << fixed << ans2 << "\n";
    }
}

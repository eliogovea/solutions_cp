#include <bits/stdc++.h>

using namespace std;

double solve1(double r1, double r2) {
    double OB = (r1 + r2) * r2 / (r1 - r2);
    double OA = OB + r1 + r2;
    double area = r1 * sqrt(OA * OA - r1 * r1);
    double angle = acos(r1 / OA);
    area -= r1 * r1 * angle;
    const double eps = 1e-9;
    double cur = r2;
    double len = OB;
    while (M_PI * cur * cur >= eps) {
        area -= M_PI * cur * cur;
        double newcur = (cur * len - cur * cur) / (len + cur);
        double newlen = len - cur - newcur;
        cur = newcur;
        len = newlen;
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    int r1, r2;
    while (cin >> r1 >> r2) {
        if (r1 == 0 && r2 == 0) break;
        cout.precision(13);
        cout << solve1(r1, r2) << "\n";
    }
}

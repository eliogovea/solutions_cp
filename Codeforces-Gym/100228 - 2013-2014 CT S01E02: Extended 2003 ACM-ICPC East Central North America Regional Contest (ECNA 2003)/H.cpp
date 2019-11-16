// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228H

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct pt {
    double x;
    double y;
    pt() {}
    pt(double _x, double _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

double cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(3);
    //freopen("dat.txt","r",stdin);

    for (int cas = 1; true; cas++) {
        vector <pt> points(8);
        for (int i = 0; i < 4; i++) {
            cin >> points[2 * i].x >> points[2 * i].y;
        }
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            double x = (points[2 * i].x + points[2 * ((i + 1) % 4)].x) / 2.0;
            double y = (points[2 * i].y + points[2 * ((i + 1) % 4)].y) / 2.0;
            if (abs(x) >= EPS || abs(y) > EPS) {
                ok = true;
            }
            points[2 * i + 1] = pt(x, y);
        }
        if (!ok) {
            break;
        }
        vector <double> area(8);
        for (int i = 2; i < 8; i++) {
            area[i] = area[i - 1] + abs(cross(points[i - 1] - points[0], points[i] - points[0])) / 2.0;
        }
        double bestDiff = 1e18;
        double ansA1;
        double ansA2;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                double a1 = area[j] - area[i] - abs(cross(points[i] - points[0], points[j] - points[0])) / 2.0;
                double a2 = area[7] - a1;
                if (abs(a1 - a2) < bestDiff) {
                    bestDiff = abs(a1 - a2);
                    ansA1 = a1;
                    ansA2 = a2;
                }
            }
        }
        if (ansA1 > ansA2) {
            swap(ansA1, ansA2);
        }

        cout << "Cake " << cas << ": " << fixed << ansA1 << " " << ansA2 << "\n";
    }
}

// 2016 USP Try-outs
// 101064A

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    double h, w;
    cin >> h >> w;
    vector <pair <double, double> > p(4);
    for (int i = 0; i < 4; i++) {
        cin >> p[i].first >> p[i].second;
    }
    double x0 = p[0].first;
    double y0 = p[0].second;
    double x1 = p[1].first - p[0].first;
    double y1 = p[1].second - p[0].second;
    //double l1 = sqrt(x1 * x1 + y1 * y1);
    //x1 /= l1;
    //y1 /= l1;
    double x2 = p[3].first - p[0].first;
    double y2 = p[3].second - p[0].second;
    //double l2 = sqrt(x2 * x2 + y2 * y2);
    //x2 /= l2;
    //y2 /= l2;
    double a = x1 / w - 1.0;
    double b = x2 / h;
    double c = y1 / w;
    double d = y2 / h - 1.0;
    double D = a * d - b * c;
    double D1 = (-x0) * d - (-y0) * b;
    double D2 = a * (-y0) - c * (-x0);
    double x = D1 / D;
    double y = D2 / D;
    cout.precision(13);
    cout << fixed << x << " " << fixed << y << "\n";
}

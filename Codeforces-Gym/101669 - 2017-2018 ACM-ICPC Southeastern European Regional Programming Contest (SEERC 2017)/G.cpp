// 2017-2018 ACM-ICPC Southeastern European Regional Programming Contest (SEERC 2017)
// 101669G

#include <bits/stdc++.h>

using namespace std;

double solve(vector <pair <double, double> > & a) {
    double v = 0.0;
    double t = 0.0;
    double s = 0.0;

    for (auto p : a) {
        double ai = p.first;
        double ti = p.second;
        s += v * ti + ai * ti * ti / 2.0;
        v += ai * ti;
        t += ti;
    }

    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(1);

    int n;
    cin >> n;

    vector <pair <double, double> > a(n);
    for (auto & p : a) {
        cin >> p.first >> p.second;
    }

    double s = solve(a);

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    double smax = solve(a);

    cout << fixed << smax - s << "\n";
}

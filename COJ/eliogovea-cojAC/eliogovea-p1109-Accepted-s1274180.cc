#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793;

void solve(double l, double & a, double & b, double & c) {
    double x = l * l;
    double y = PI * l * l / 4.0;
    double z = PI * l * l / 4.0 - PI * l * l / 3.0 + sqrt(3.0) * l * l / 4.0;

    c = x - y - z;
    b = z - c;
    a = x - 4.0 * b - 4.0 * c;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(3);


    double l;
    double a, b, c;
    while (cin >> l) {
        solve(l, a, b, c);
        cout << fixed << a << " " << 4.0 * b << " " << 4.0 * c << "\n";
    }
}

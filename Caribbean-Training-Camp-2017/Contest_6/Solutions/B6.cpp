#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(14);

    int n;
    double s, t;
    cin >> n >> t >> s;
    int e = s + t;
    for (int i = 0; i < n; i++) {
        double ss;
        cin >> ss;

        double ans = (t + s + ss) / 2.0;
        cout << fixed << ans << "\n";
    }
}

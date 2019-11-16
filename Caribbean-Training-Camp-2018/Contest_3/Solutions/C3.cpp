#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
int c[N + 10];
int s[(1 << N) + 10];
double e[(1 << N) + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cout.precision(13);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[1 << i] = c[i];
    }

    for (int m = 1; m < (1 << n); m++) {
        s[m] = s[m ^ (m & -m)] + s[m & -m];
    }

    double t = s[(1 << n) - 1];

    e[(1 << n) - 1] = 0.0;

    for (int m = (1 << n) - 2; m >= 0; m--) {
        e[m] = 1.0;
        for (int i = 0; i < n; i++) {
            if (!(m & (1 << i))) {
                e[m] += e[m | (1 << i)] * (double)c[i] / t;
            }
        }
        e[m] /= (1.0 - (double)s[m] / t);
    }

    cout << fixed << e[0] << "\n";
}

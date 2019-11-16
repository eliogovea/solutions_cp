#include <bits/stdc++.h>

using namespace std;

const int S = 10 * 1000 + 10;

int n;
string s;
string p = "papa";
long long f[10][S];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 4; j++) {
            f[j][i + 1] += f[j][i];
            if (j < 4 && s[i] == p[j]) {
                f[j + 1][i + 1] += f[j][i];
            }
        }
    }

    cout << f[4][n] << "\n";
}

// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606F

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen( "dat.txt", "r", stdin );

    int n, k;
    cin >> n >> k;

    vector <vector <LD> > f(k + 1, vector <LD> (n + 1));

    f[0][0] = 1.0;

    for (int i = 0; i < k; i++) {
        for (int c = 0; c < n; c++) {
            f[i + 1][c] += (LD)0.5 * f[i][c];
            f[i + 1][c + 1] += (LD)0.5 * f[i][c];
        }
        f[i + 1][n] += (LD)0.5 * f[i][n];
        f[i + 1][n - 1] += (LD)0.5 * f[i][n];
    }

    LD ans = 0.0;
    for (int i = 1; i <= n; i++) {
        ans += f[k][i] * (LD)i;
    }

    cout.precision(13);
    cout << fixed << ans << "\n";
}

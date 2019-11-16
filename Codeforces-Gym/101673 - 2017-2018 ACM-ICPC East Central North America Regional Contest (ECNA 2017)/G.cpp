// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673G

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector <int> c;
    int x = m;
    while (x > 0) {
        c.push_back(x);
        x = 2 * x / 3;
    }
    c.push_back(0);

    const int INF = 1e7;

    int f[n + 1][c.size() + 1][2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c.size(); j++) {
            for (int k = 0; k < 2; k++) {
                f[i][j][k] = -INF;
            }
        }
    }

    f[0][0][true] = 0;

    for (int step = 0; step < n; step++) {
        for (int can = 0; can < c.size(); can++) {
            // pre = true
            if (f[step][can][true] != -INF) {
                if (c[can] != 0) {
                    f[step + 1][can + 1][true] = max(f[step + 1][can + 1][true], f[step][can][true] + min(v[step], c[can]));
                    f[step + 1][max(can - 1, 0)][false] = max(f[step + 1][max(can - 1, 0)][false], f[step][can][true]);
                } else {
                    f[step + 1][max(can - 1, 0)][false] = max(f[step + 1][max(can - 1, 0)][false], f[step][can][true]);
                }
            }

            // pre = false;
            if (f[step][can][false] != -INF) {
                if (c[can] != 0) {
                    f[step + 1][can + 1][true] = max(f[step + 1][can + 1][true], f[step][can][false] + min(v[step], c[can]));
                    f[step + 1][0][false] = max(f[step + 1][0][false], f[step][can][false]);
                } else {
                    f[step + 1][0][false] = max(f[step + 1][0][false], f[step][can][false]);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < 2; j++) {
            answer = max(answer, f[n][i][j]);
        }
    }

    cout << answer << "\n";
}

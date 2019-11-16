// 2014-2015 CT S02E10: Codeforces Trainings Season 2 Episode 10 - 2014 Amirkabir University of Technology Annual Programming Contest (AUT APC 14)
// 100534D

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1005;

const LL MOD = 1000000007;

LL n;
string s[N];

LL dp1[N][N], dp2[N][N];
LL w1[N][N], w2[N][N];

int q, r1, r2, c1, c2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    dp1[0][0] = (s[0][0] == 'C');
    w1[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp1[0][i] = dp1[0][i - 1] + (s[0][i] == 'C');
        w1[0][i] = w1[0][i - 1];
        dp1[i][0] = dp1[i - 1][0] + (s[i][0] == 'C');
        w1[i][0] = w1[i - 1][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (dp1[i - 1][j] == dp1[i][j - 1]) {
                dp1[i][j] = dp1[i - 1][j] + (s[i][j] == 'C');
                w1[i][j] = w1[i - 1][j] + w1[i][j - 1];
            } else if (dp1[i - 1][j] > dp1[i][j - 1]) {
                dp1[i][j] = dp1[i - 1][j] + (s[i][j] == 'C');
                w1[i][j] = w1[i - 1][j];
            } else {
                dp1[i][j] = dp1[i][j - 1] + (s[i][j] == 'C');
                w1[i][j] = w1[i][j - 1];
            }
            w1[i][j] %= MOD;
        }
    }
    dp2[n - 1][n - 1] = (s[n - 1][n - 1] == 'C');
    w2[n - 1][n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp2[n - 1][i] = dp2[n - 1][i + 1] + (s[n - 1][i] == 'C');
        w2[n - 1][i] = w2[n - 1][i + 1];
        dp2[i][n - 1] = dp2[i + 1][n - 1] + (s[i][n - 1] == 'C');
        w2[i][n - 1] = w2[i + 1][n - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (dp2[i + 1][j] == dp2[i][j + 1]) {
                dp2[i][j] = dp2[i + 1][j] + (s[i][j] == 'C');
                w2[i][j] = w2[i + 1][j] + w2[i][j + 1];
            } else if (dp2[i + 1][j] > dp2[i][j + 1]) {
                dp2[i][j] = dp2[i + 1][j] + (s[i][j] == 'C');
                w2[i][j] = w2[i + 1][j];
            } else {
                dp2[i][j] = dp2[i][j + 1] + (s[i][j] == 'C');
                w2[i][j] = w2[i][j + 1];
            }
            w2[i][j] %= MOD;
        }
    }
    cin >> q;
    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        LL b1 = -1;
        LL ww1 = 0;
        for (int i = c1 - 1; i >= 0; i--) {
            LL x = r2 + 1;
            LL y = i;
            LL cnt = dp1[x][y] + dp2[x][y] - (s[x][y] == 'C');
            if (cnt > b1) {
                b1 = cnt;
                ww1 = (long long)w1[x][y] * w2[x][y] % MOD;
            } else if (cnt == b1) {
                if (x + 1 < n) {
                    LL tmp = dp1[x][y] + dp2[x + 1][y];
                    if (tmp == b1) {
                        ww1 += (w1[x][y] * w2[x + 1][y]) % MOD;
                        ww1 %= MOD;
                    }
                }
            }
        }
        LL b2 = -1;
        LL ww2 = 0;
        for (int i = r1 - 1; i >= 0; i--) {
            LL x = i;
            LL y = c2 + 1;
            LL cnt = dp1[x][y] + dp2[x][y] - (s[x][y] == 'C');
            if (cnt > b2) {
                b2 = cnt;
                ww2 = (w1[x][y] * w2[x][y]) % MOD;
            } else if (cnt == b2) {
                if (y + 1 < n) {
                    LL tmp = dp1[x][y] + dp2[x][y + 1];
                    if (tmp == b2) {
                        ww2 += (w1[x][y] * w2[x][y + 1]) % MOD;
                        ww2 %= MOD;
                    }
                }
            }
        }
        if (b1 == -1 && b2 == -1) {
            cout << "0 0\n";
            continue;
        }
        LL b, w;
        if (b1 == b2) {
            b = b1;
            w = (ww1 + ww2) % MOD;
        } else if (b1 > b2) {
            b = b1;
            w = ww1;
        } else {
            b = b2;
            w = ww2;
        }
        cout << b << " " << w << "\n";
    }
}

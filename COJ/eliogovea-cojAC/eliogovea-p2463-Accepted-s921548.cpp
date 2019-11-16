/// sUrPRise

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

const int M = 55;

int tc;
int m, t;
string s[M];
int val[M];
int steps1[M];
int steps2[M];
int next1[M];
int next2[M];

double dp[M][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(4);

    //freopen("dat.txt", "r", stdin);

    cin >> tc;

    while (tc--) {
        cin >> m >> t;

        for (int i = 0; i <= m + 1; i++) {
            val[i] = 0;
            s[i] = "";
            next1[i] = 0;
            next2[i] = 0;
            steps1[i] = 1;
            steps2[i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            cin >> s[i];
            if (s[i] != "L") {
                if (s[i] != "0") {
                    bool pos = (s[i][0] == '+');
                    for (int j = 1; s[i][j]; j++) {
                        val[i] = 10 * val[i] + s[i][j] - '0';
                    }
                    if (!pos) {
                        val[i] = -val[i];
                    }
                }

            }
        }
        s[m + 1] = "";
        for (int i = 0; i <= m; i++) {
            int x = i + 1;
            if (x >= m + 1) {
                x = m + 1;
                next1[i] = x;
            } else {
                if (s[x] != "L") {
                    x += val[x];
                    if (x > m + 1) {
                        x = m + 1;
                    } else if (x < 0) {
                        x = 0;
                    }
                } else {
                    steps1[i]++;
                }
                next1[i] = x;
            }
            x = i + 2;
            if (x >= m + 1) {
                x = m + 1;
                next2[i] = x;
            } else {
                if (s[x] != "L") {
                    x += val[x];
                    if (x > m + 1) {
                        x = m + 1;
                    } else if (x < 0) {
                        x = 0;
                    }
                } else {
                    steps2[i]++;
                }
                next2[i] = x;
            }
        }

        for (int i = 0; i <= t; i++) {
            for (int j = 0; j <= m + 1; j++) {
                dp[i][j] = 0.0;
            }
        }
        next1[m + 1] = next2[m + 1] = m + 1;
        dp[0][0] = 1.0;
        for (int i = 0; i < t; i++) {
            for (int j = 0; j <= m + 1; j++) {
                dp[i + steps1[j]][next1[j]] += 0.5 * dp[i][j];
                dp[i + steps2[j]][next2[j]] += 0.5 * dp[i][j];
            }
        }
        double ans = dp[t][m + 1];

        if (fabs(ans - 0.5) < EPS) {
            cout << "Push. 0.5000\n";
        } else if (ans < 0.5) {
            cout << "Bet against. " << fixed << ans << "\n";
        } else {
            cout << "Bet for. " << fixed << ans << "\n";
        }
    }
}

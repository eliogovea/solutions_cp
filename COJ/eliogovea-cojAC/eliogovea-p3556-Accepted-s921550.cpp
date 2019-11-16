/// sUrPRise

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int a, m;
int n, sz[25], v[25][1205];

int dp[25][1005];
int rec[25][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(4);

    //freopen("dat.txt", "r", stdin);

    cin >> a >> m;


    for (int i = 1; i <= a; i++) {
        cin >> sz[i];
        for (int j = 1; j <= sz[i]; j++) {
            cin >> v[i][j];
        }
        for (int j = 1; j <= sz[i]; j++) {
            v[i][j] += v[i][j - 1];
        }
    }

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] = dp[i][j];
            rec[i + 1][j] = 0;
        }

        for (int j = 0; j <= m; j++) {
            for (int k = 0; k + j <= m && k <= sz[i + 1]; k++) {
                int val = dp[i][j] + v[i + 1][k];
                if (val < dp[i + 1][j + k]) {
                    dp[i + 1][j + k] = val;
                    rec[i + 1][j + k] = k;
                }
            }
        }
    }

    int pos = 0;
    int ans = 0;
    for (int i = 0; i <= m; i++) {

        int val = 10 * i - dp[a][i];
        if (val > ans) {
            ans = val;
            pos = i;
        }
    }
    cout << ans << " " << pos << "\n";
    vector <int> x(a + 5);
    for (int i = a; i >= 1; i--) {
        x[i] = rec[i][pos];
        pos -= rec[i][pos];
    }
    for (int i = 1; i <= a; i++) {
        cout << x[i];
        if (i + 1 <= a) {
            cout << " ";
        }
    }
    cout << "\n";
}

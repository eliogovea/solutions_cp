#include <bits/stdc++.h>

using namespace std;


int n, m;
string a, b;
long long dp[15][100005];

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n >> m >> a >> b;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[j][i] = dp[j][i - 1];
            if (j != 0 && b[i - 1] == a[j - 1]) {
                dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % MOD;
            }
        }
    }

    cout << dp[n][m] << "\n";
}

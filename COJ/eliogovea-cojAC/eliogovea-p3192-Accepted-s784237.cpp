#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 250;

int dp[N + 5][N + 5];

int main() {
    //freopen("dat.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; j + k <= N; k++) {
                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % mod;
            }
        }
    }
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << dp[k][n] << "\n";
    }
}

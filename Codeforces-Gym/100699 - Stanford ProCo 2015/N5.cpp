// Stanford ProCo 2015
// 100699N5

#include <bits/stdc++.h>

using namespace std;

long long dp[3][11][11][11];

long long solve(int last, int a, int b, int c) {
    if (dp[last][a][b][c] != -1) {
        return dp[last][a][b][c];
    }
    if (a == 0 && b == 0 && c == 0) {
        return 1;
    }
    int res = 0;
    if (a > 0 && last != 0) {
        res += solve(0, a - 1, b, c);
    }
    if (b > 0 && last != 1) {
        res += solve(1, a, b - 1, c);
    }
    if (c > 0 && last != 2) {
        res +=solve(2, a, b, c - 1);
    }
    dp[last][a][b][c] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                for (int l = 0; l <= n; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    long long ans = 0;
    ans += 3LL * solve(0, n - 1, n, n);
    cout << ans << "\n";
}

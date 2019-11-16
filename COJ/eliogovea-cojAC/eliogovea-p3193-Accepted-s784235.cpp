#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 2000;

int add(int &a, int b) {
    a = (a + b) % mod;
}

int a, b, c;
int dp[N + 5][N + 5][2];

int main() {
    //freopen("dat.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    dp[1][1][0] = 1;
    dp[1][0][1] = (c > 0);

    for (int i = 1; i <= a + b; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= 1; k++) {
                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
                if (j + 1 <= a) {
                    add(dp[i + 1][j + 1][0], dp[i][j][k]);
                }
                if ((i - j) + 1 <= b && ( c + j - (i - j) > 0 )) {
                    add(dp[i + 1][j][1], dp[i][j][k]);
                }
            }
        }
    }
    cout << (dp[a + b][a][0] + dp[a + b][a][1]) % mod << "\n";
}
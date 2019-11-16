#include <iostream>

using namespace std;

const int MAXN = 1005, MAXK = 55, mod = 1000000007;

int tc, N, K, x, dp[MAXK][MAXN];

int main() {
    cin >> tc;
    while (tc--) {
        cin >> N >> K;
        for (int i = 0; i <= K; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = K - 1; j >= 0; j--)
                for (int k = 0; k < N; k++) {
                    dp[j + 1][(k + i) % N] += dp[j][k];
                    dp[j + 1][(k + i) % N] %= mod;
                }
            dp[1][i]++;
            dp[1][i] %= mod;
        }
        cout << dp[K][0] << "\n";
    }
}

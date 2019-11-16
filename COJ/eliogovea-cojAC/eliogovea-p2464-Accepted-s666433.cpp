#include <cstdio>

const int mod = 1000000007;

int tc, N, K, dp[55][1005];

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &N, &K);
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
        printf("%d\n", dp[K][0]);
    }
}

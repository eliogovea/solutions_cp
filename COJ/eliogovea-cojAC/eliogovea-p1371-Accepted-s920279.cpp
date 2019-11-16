#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000009;

inline void add(int &a, int b) {
    if ((a += b) >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (long long)a * b % MOD;
}

const int N = 55;

int t;
int n, d;
int arr[N];
int sum[N];

int dp[5][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);

	cin >> t;

	while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum[i] = sum[i - 1];
            add(sum[i], arr[i]);
        }

        int cur = 0;

        for (int i = 1; i <= n; i++) {
            dp[cur][i][i] = arr[i];
            for (int j = i - 1; j >= 1; j--) {
                dp[cur][j][i] = sum[i];
                add(dp[cur][j][i], MOD - sum[j - 1]);
                add(dp[cur][j][i], dp[cur][j + 1][i]);
                //if (i > 1) {
                    add(dp[cur][j][i], dp[cur][j][i - 1]);
                    if (j + 1 <= i - 1) {
                        add(dp[cur][j][i], MOD - dp[cur][j + 1][i - 1]);
                    }
                //}
            }
        }

        for (int i = 1; i < d; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = j; k <= n; k++) {
                    dp[cur ^ 1][j][k] = dp[cur][j][k];
                }
            }

            for (int j = 1; j <= n; j++) {
                for (int k = j - 1; k >= 1; k--) {
                    add(dp[cur ^ 1][k][j], dp[cur ^ 1][k + 1][j]);
                    //if (j > 1) {
                        add(dp[cur ^ 1][k][j], dp[cur ^ 1][k][j - 1]);
                        if (k + 1 <= j - 1) {
                            add(dp[cur ^ 1][k][j], MOD - dp[cur ^ 1][k + 1][j - 1]);
                        }
                    //}

                }
            }
            cur ^= 1;
        }
        cout << dp[cur][1][n] << "\n";
	}

}

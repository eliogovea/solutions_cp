#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int n, k;
int x[25], y[25];

int cnt[1 << 17];
int dp[1 << 17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = INF;
    }
    for (int i = 1; i < (1 << n); i++) {
        cnt[i] = 0;
        int maxx = -INF;
        int maxy = -INF;
        int minx = INF;
        int miny = INF;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                maxx = max(maxx, x[j] + k);
                minx = min(minx, x[j] - k);
                maxy = max(maxy, y[j] + k);
                miny = min(miny, y[j] - k);
            }
        }
        cnt[i] = 2 * (maxx - minx + maxy - miny);
    }

    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j > 0; j = (j - 1) & i) {
            dp[i] = min(dp[i], dp[i ^ j] + cnt[j]);
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}

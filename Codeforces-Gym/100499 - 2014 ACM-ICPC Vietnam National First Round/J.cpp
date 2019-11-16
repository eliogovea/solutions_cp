// 2014 ACM-ICPC Vietnam National First Round
// 100499J

#include <bits/stdc++.h>

using namespace std;

int t;
int n, m, k, a;
long long dp[10005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i <= m; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> a;
            for (int i = m; i >= a; i--) {
                dp[i] += dp[i - a];
                if (dp[i] > k) {
                    dp[i] = k;
                }
            }
        }
        if (dp[m] >= k) {
            cout << "ENOUGH\n";
        } else {
            cout << dp[m] << "\n";
        }
    }
}

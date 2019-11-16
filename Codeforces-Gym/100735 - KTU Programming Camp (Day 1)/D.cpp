// KTU Programming Camp (Day 1)
// 100735D

#include <bits/stdc++.h>

using namespace std;

int dp[1 << 16];

int n, a[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] > ans) {
            ans = dp[i];
        }
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                for (int k = j + 1; k < n; k++) {
                    if (k != j && !(i & (1 << k))) {
                        for (int l = k + 1; l < n; l++) {
                            if (l != j && l != k && !(i & (1 << l))) {
                                if (a[j] + a[k] > a[l]) {
                                    if (dp[i | (1 << j) | (1 << k) | (1 << l)] < dp[i] + 1) {
                                        dp[i | (1 << j) | (1 << k) | (1 << l)] = dp[i] + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

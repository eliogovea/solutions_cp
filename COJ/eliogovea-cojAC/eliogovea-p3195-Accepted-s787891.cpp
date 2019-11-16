#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, t, x;
bool dp[N + 5];
int ans = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(false);
    cin >> n;
    dp[0] = true;
    while (n--) {
        cin >> x;
        t += x;
        for (int i = N; i >= x; i--) {
            dp[i] |= dp[i - x];
        }
    }
    for (int i = 0; i <= t; i++) {
        if (dp[i]) {
            int tmp = i * i + (t - i) * (t - i);
            if (ans == -1 || tmp < ans) {
                ans = tmp;
            }
        }
    }
    cout << ans << "\n";
}
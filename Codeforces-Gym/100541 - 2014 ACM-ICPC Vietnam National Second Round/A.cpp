// 2014 ACM-ICPC Vietnam National Second Round
// 100541A

#include <bits/stdc++.h>

using namespace std;

int t, n, w, p[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> w;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (p[j] > p[i]) {
                    int tmp = (p[j] - p[i]) * (w / p[i]);
                    if (tmp > ans) {
                        ans = tmp;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

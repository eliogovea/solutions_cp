// KTU Programming Camp (Day 3)
// 100739B

#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
const int MAX = 500;

int n, a[N], Q, p, q;

int sum[MAX + 2][MAX + 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> Q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (Q--) {
        cin >> q >> p;
        if (p == 0 || p <= q) {
            cout << "0\n";
            continue;
        }
        if (p <= MAX) {
            if (sum[p][q] != 0) {
                cout << sum[p][q] << "\n";
            } else {
                for (int i = q; i < n; i += p) {
                    sum[p][q] += a[i];
                }
                cout << sum[p][q] << "\n";
            }
        } else {
            int ans = 0;
            for (int i = q; i < n; i += p) {
                ans += a[i];
            }
            cout << ans << "\n";
        }
    }
}

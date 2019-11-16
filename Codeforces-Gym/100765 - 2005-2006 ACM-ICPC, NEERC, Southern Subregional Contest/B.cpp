// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765B

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m;
    int ans = 0;
    while (m--) {
        cin >> x;
        ans += x;
        ans %= n;
    }
    cout << ans << "\n";
}

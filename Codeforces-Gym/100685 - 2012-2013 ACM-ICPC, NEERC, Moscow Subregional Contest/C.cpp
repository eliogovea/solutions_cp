// 2012-2013 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100685C

#include <bits/stdc++.h>

using namespace std;

int n, l[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        sum += l[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] * n > sum) ans++;
    }
    cout << ans << "\n";
}
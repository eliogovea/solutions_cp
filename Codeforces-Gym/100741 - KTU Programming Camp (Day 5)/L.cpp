// KTU Programming Camp (Day 5)
// 100741L

#include <bits/stdc++.h>

using namespace std;

int n, m, sz;
int skill[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    sz = n + m;
    for (int i = 0; i < sz; i++) {
        cin >> skill[i];
    }
    int ans = 0;
    for (int i = 1; i < (1 << sz); i++) {
        long long red = 0;
        long long blue = 0;
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) {
                if (j < n) {
                    red += skill[j];
                } else {
                    blue += skill[j];
                }
            }
        }
        if (red == blue) {
            ans++;
        }
    }
    cout << ans << "\n";
}

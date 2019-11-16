#include <iostream>

using namespace std;

int t;
int n, cnt[10];

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }
        int ans = cnt[4];
        ans += cnt[3];
        if (cnt[1] > cnt[3]) {
            cnt[1] -= cnt[3];
        } else {
            cnt[1] = 0;
        }
        ans += cnt[2] / 2;
        if (cnt[2] & 1) {
            cnt[2] = 1;
        } else {
            cnt[2] = 0;
        }
        if (cnt[2] != 0) {
            ans++;
            cnt[1] -= 2;
        }
        if (cnt[1] > 0) {
            ans += cnt[1] / 4;
            if (cnt[1] % 4) {
                ans++;
            }
        }
        cout << ans << "\n";
    }

}
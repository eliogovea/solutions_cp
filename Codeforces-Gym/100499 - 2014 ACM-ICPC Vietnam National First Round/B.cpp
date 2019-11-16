// 2014 ACM-ICPC Vietnam National First Round
// 100499B

#include <bits/stdc++.h>

using namespace std;

const int M = 10000005;

int t;
int n, k, s, c1, c2, m;

int cnt[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s >> c1 >> c2 >> m;
        for (int i = 0; i < m; i++) {
            cnt[i] = 0;
        }
        int v = s;
        for (int i = 0; i < n; i++) {
            if (s < m) {
                cnt[s]++;
            }
            s = (1LL * c1 * s + c2) % m;
        }
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << i << " ";
                sum++;
                if (sum == k) {
                    break;
                }
            }
            if (sum == k) {
                break;
            }
        }
        if (sum != k) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

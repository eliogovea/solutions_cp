#include <bits/stdc++.h>

using namespace std;

int n, a[500], b[500];
int ca[500], cb[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[x]++;
        b[y]++;
        int pa = 1;
        int pb = 100;
        for (int i = 1; i <= 100; i++) {
            ca[i] = a[i];
            cb[i] = b[i];
        }
        int ans = 0;
        while (true) {
            while (pa <= n && ca[pa] == 0) {
                pa++;
            }
            while (pb >= 1 && cb[pb] == 0) {
                pb--;
            }
            if (pa == n + 1 || pb == 0) {
                break;
            }
            ans = max(ans, pa + pb);
            if (ca[pa] == cb[pb]) {
                pa++;
                pb--;
            } else if (ca[pa] > cb[pb]) {
                ca[pa] -= cb[pb];
                pb--;
            } else {
                cb[pb] -= ca[pa];
                pa++;
            }
        }
        cout << ans << "\n";
    }
}

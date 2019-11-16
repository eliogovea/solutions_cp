#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;

int f['z' + 15];
int cur['z' + 15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);

    cin >> n >> m >> a >> b;

    if (m < n) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cur[b[i]]++;
    }

    int cnt = 0;

    for (char i = 'A'; i <= 'Z'; i++) {
        if (cur[i] == f[i]) {
            cnt++;
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (cur[i] == f[i]) {
            cnt++;
        }
    }

    int t = 2 * ('Z' - 'A' + 1);
    int ans = 0;
    if (cnt == t) {
        ans++;
    }

    for (int i = n; i < m; i++) {
        if (cur[ b[ i - n ] ] == f[b[i - n]]) {
            cnt--;
        }
        if (cur[b[i - n]] == f[b[i - n]] + 1) {
            cnt++;
        }
        cur[b[i - n]]--;
        if (cur[b[i]] == f[b[i]]) {
            cnt--;
        }
        if (cur[b[i]] == f[b[i]] - 1) {
            cnt++;
        }
        cur[b[i]]++;
        if (cnt == t) {
            ans++;
        }
    }
    cout << ans << "\n";
}
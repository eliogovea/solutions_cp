#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

int n, m;
int a[N];
vector <int> v[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> m;

    int sqrtn = 1 + sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i / sqrtn].push_back(a[i]);
    }

    for (int i = 0; i <= (n - 1) / sqrtn; i++) {
        sort(v[i].begin(), v[i].end());
    }

    string op;
    int x, y, z, t;
    while (m--) {
        cin >> op;
        if (op[0] == 'S') {
            cin >> x >> y;
            x--;
            if (y == a[x]) {
                continue;
            }
            int p = x / sqrtn;
            v[p].erase(lower_bound(v[p].begin(), v[p].end(), a[x]));
            v[p].insert(upper_bound(v[p].begin(), v[p].end(), y), y);
            a[x] = y;
        } else {
            cin >> x >> y >> z >> t;
            if (x > y) {
                swap(x, y);
            }
            if (z > t) {
                swap(z, t);
            }
            x--;
            y--;
            int px = x / sqrtn;
            int py = y / sqrtn;
            int ans = 0;
            if (px == py) {
                for (int i = x; i <= y; i++){
                    if (z <= a[i] && a[i] <= t) {
                        ans++;
                    }
                }
            } else {
                while (x % sqrtn != 0) {
                    if (z <= a[x] && a[x] <= t) {
                        ans++;
                    }
                    x++;
                }
                while (y % sqrtn != sqrtn - 1) {
                    if (z <= a[y] && a[y] <= t) {
                        ans++;
                    }
                    y--;
                }
                px = x / sqrtn;
                py = y / sqrtn;
                if (px <= py) {
                    for (int i = px; i <= py; i++) {
                        ans += upper_bound(v[i].begin(), v[i].end(), t) - lower_bound(v[i].begin(), v[i].end(), z);
                    }
                }
            }
            cout << ans << "\n";
        }
    }
}

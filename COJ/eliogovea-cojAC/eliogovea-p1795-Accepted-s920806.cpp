#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int t;
int n;
long long k;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];

        }
        sort(a, a + n);
        int lo = 0;
        int hi = n - 1;
        int x = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int pos = upper_bound(a, a + n, a[mid]) - a;
            if ((long long)pos * n >= k) {
                x = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        k -= (long long)x * n;
        lo = 0;
        hi = n - 1;
        int y = -1;
        int total = upper_bound(a, a + n, a[x]) - lower_bound(a, a + n, a[x]);

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int pos = upper_bound(a, a + n, a[mid]) - a;
            if ((long long)total * pos >= k) {
                y = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        assert(x != -1);
        assert(y != -1);
        cout << a[x] << " " << a[y] << "\n";
    }

}

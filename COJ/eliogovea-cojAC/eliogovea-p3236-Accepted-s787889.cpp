#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100005], b[100005];
long long ans, mx;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);
    //freopen("dat.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    long long ans = 0;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        ans += b[i] - a[i];
        int p = upper_bound(b, b + n, a[i] + m) - b;
        if (p != 0) {
            p--;
            long long diff = b[p] - a[i];
            if (diff > mx) {
                mx = diff;
            }
        }
    }
    cout << ans - mx << "\n";
}
// 2016 USP Try-outs
// 101064D

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    LL n, k;
    cin >> n >> k;
    vector <LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    LL lo = a[0] + a[1];
    LL hi = a[n - 1] + a[n - 2];
    LL ans = hi;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1LL;
        LL cnt = 0;
        for (int i = 0; i < n && a[i] <= mid; i++) {
            LL pos = upper_bound(a.begin(), a.end(), mid - a[i]) - a.begin();
            if (pos > i) {
                cnt += pos - i - 1LL;
            }
        }
        if (cnt >= k) {
            ans = mid;
            hi = mid - 1LL;
        } else {
            lo = mid + 1LL;
        }
    }
    cout << ans << "\n";
}

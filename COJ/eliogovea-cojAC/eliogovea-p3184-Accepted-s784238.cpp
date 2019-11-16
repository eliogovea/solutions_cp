#include <bits/stdc++.h>

using namespace std;

long long k, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> k >> d;
    long long lo = 0, hi = 1e15, mid, val;
    long long ans = hi;
    while (lo <= hi) {
        mid = (lo + hi) >> 1LL;
        val = 1 + (long long)(double(mid) * log10((double)k));
        if (val >= d) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}



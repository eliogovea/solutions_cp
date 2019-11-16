// 2015-2016 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100792C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    int lo = 1;
    int hi = 1e9;
    int x = 0;
    int y = 0;
    int ans;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        cout << mid - 1 << " " << y << endl;
        cin >> ans;
        cout << mid << " " << y << endl;
        cin >> ans;
        if (ans == 1) {
            x = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    lo = 1;
    hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        cout << x << " " << mid - 1 << endl;
        cin >> ans;
        cout << x << " " << mid << endl;
        cin >> ans;
        if (ans == 1) {
            y = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << "A " << x << " " << y << endl;
}

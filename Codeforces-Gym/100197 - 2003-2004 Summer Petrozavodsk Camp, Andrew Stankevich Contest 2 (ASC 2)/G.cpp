// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 2 (ASC 2)
// 100197G

#include <bits/stdc++.h>

using namespace std;

int n, m, y;
int x[1005], k[1005];

pair<int, int> arr[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> y;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        k[i] = (x[i] * m) / y;
        arr[i].first = x[i] * m - k[i] * y;
        arr[i].second = i;
        sum += k[i];
    }
    sum = m - sum;
    sort(arr, arr + n);
    int pos = n - 1;
    while (sum > 0 && pos >= 0) {
        while (sum > 0 && arr[pos].first >= y) {
            k[arr[pos].second]++;
            arr[pos].first -= y;
        }
        pos--;
    }
    sort(arr, arr + n);
    pos = n - 1;
    while (sum > 0 && pos >= 0) {
        k[arr[pos].second]++;
        sum--;
        pos--;
    }
    for (int i = 0; i < n; i++) {
        cout << k[i];
        if (i + 1 < n) cout << " ";
    }
    cout << "\n";
}

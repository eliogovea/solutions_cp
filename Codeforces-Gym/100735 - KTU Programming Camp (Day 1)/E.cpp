// KTU Programming Camp (Day 1)
// 100735E

#include <bits/stdc++.h>

using namespace std;

int n;
long long a[105][105], row[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            row[i] += a[i][j];
            sum += a[i][j];
        }
    }
    if (n == 1) {
        cout << a[0][0] << "\n";
        return 0;
    }
    sum /= (n - 1);
    for (int i = 0; i < n; i++) {
        a[i][i] = sum - row[i];
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (j + 1 < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

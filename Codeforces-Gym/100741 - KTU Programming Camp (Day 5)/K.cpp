// KTU Programming Camp (Day 5)
// 100741K

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n % 2 == 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1, cnt = 0; j < n; j++) {
            cnt++;
            cout << (cnt <= (n - 1) / 2);
            if (j + 1 < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

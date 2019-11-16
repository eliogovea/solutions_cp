// Stanford ProCo 2015
// 100699N2

#include <bits/stdc++.h>

using namespace std;

char line[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + n; j++) {
            line[j] = ' ';
        }
        line[n - 1 - i] = '/';
        line[n + i] = '\\';
        line[n + i + 1] = '\0';
        cout << line << "\n";
    }
}

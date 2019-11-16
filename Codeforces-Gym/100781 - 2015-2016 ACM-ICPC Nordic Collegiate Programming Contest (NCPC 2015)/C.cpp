// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781C

#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int p = i % 3;
        if (s[i] != "PER"[p]) ans++;
    }
    cout << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;

string s;
char c;
long long cnt[10], ac, ans;

int main() {
    cin >> s;
    cnt[0] = 1;
    for (int i = 0; s[i]; i++) {
        c = s[i];
        if (c < '0' || c > '9') {
            cnt[0] = cnt[1] = cnt[2] = 0LL;
            ac = 0LL;
            cnt[0] = 1LL;
        } else {
            ac += (long long)('0' + c);
            ac %= 3LL;
            ans += cnt[ac];
            cnt[ac]++;
        }
    }
    cout << ans << "\n";
}

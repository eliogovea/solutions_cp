// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078D

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL solve(LL n) {
    if (n == 0LL) {
        return 0LL;
    }

    LL res = 0LL;
    LL x = n / 2LL + 1LL;
    if (x <= n) {
        res += n - x + 1LL;
    }
    int y = (n - 1LL) / 3LL;
    while (3LL * y + 1LL <= n) {
        y++;
    }
    if (y % 2LL == 0LL) {
        y++;
    }
    if (n % 2LL == 0LL) {
        n--;
    }
    y = (y + 1LL) / 2LL;
    n = (n + 1LL) / 2LL;
    if (y <= n) {
        res += n - y + 1LL;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}

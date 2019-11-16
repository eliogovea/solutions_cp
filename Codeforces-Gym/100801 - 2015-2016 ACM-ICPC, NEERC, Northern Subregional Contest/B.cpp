// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801B

#include <bits/stdc++.h>

using namespace std;

vector <string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    int b, w;
    cin >> b >> w;
    bool x = false;
    string s = "@.";
    if (b == w) {
        cout << b << " 2\n";
        for (int i = 0; i < b; i++) {
            cout << s << "\n";
            swap(s[0], s[1]);
        }
        return 0;
    }

    while (b > 1 && w > 1) {
        ans.push_back(s);
        swap(s[0], s[1]);
        x = true;
        b--;
        w--;
    }
    if (b > 1) {
        if (x) ans.push_back("@@");
        while (b) {
            ans.push_back("..");
            ans.push_back(".@");
            b--;
        }
    }
    if (w > 1) {
        if (x) ans.push_back("..");
        while (w) {
            ans.push_back("@@");
            ans.push_back(".@");
            w--;
        }
    }
    cout << ans.size() << " 2\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}

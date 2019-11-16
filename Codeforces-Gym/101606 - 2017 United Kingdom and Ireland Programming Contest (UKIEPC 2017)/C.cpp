// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606C

#include <bits/stdc++.h>

using namespace std;

string c[] = {"", "red", "yellow", "green", "brown", "blue", "pink", "black"};
map <string, int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen( "dat.txt", "r", stdin );

    for (int i = 1; i <= 7; i++) {
        v[c[i]] = i;
    }

    int n;
    cin >> n;

    vector <int> a;
    int r = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (v[s] == 1) {
            r++;
        } else {
            a.push_back(v[s]);
        }
    }

    sort(a.begin(), a.end());

    if (!a.size()) {
        cout << 1 << "\n";
    } else {
        int ans = a.back() * (r + 1) + r;
        for (int i = 0; i + 1 < a.size(); i++) {
            ans += a[i];
        }
        cout << ans << "\n";
    }
}

// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801C

#include <bits/stdc++.h>

using namespace std;

string a, b;
long long pre['z' + 5], suf['z' + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    cin >> a >> b;
    long long ans = (long long)a.size() * (long long)b.size();
    for (int i = 1; a[i]; i++) {
        pre[a[i]]++;
    }
    for (int i = 0; i < b.size() - 1; i++) {
        suf[b[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        ans -= pre[i] * suf[i];
    }
    cout << ans << "\n";
}
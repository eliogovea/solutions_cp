// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078A

#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[100005];
int b[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        set <int> S;
        vector <int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (S.find(a[i]) != S.end()) {
                S.erase(S.find(a[i]));
            } else {
                S.insert(a[i]);
            }
            if (S.find(b[i]) != S.end()) {
                S.erase(S.find(b[i]));
            } else {
                S.insert(b[i]);
            }
            if (S.size() == 0) {
                ans.push_back(i);
            }
        }
        assert(!S.size());
        assert(ans.back() == n);
        for (int i = 1; i < ans.size(); i++) {
            cout << ans[i - 1] + 1 << "-" << ans[i];
            if (i + 1 < ans.size()) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

// 2015-2016 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100792A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    int b;
    cin >> b;
    b--;
    vector <int> ans;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            ans.push_back(i);
            if (i * i != b) {
                ans.push_back(b / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < ans.size()) cout << " ";
    }
    cout << "\n";
}

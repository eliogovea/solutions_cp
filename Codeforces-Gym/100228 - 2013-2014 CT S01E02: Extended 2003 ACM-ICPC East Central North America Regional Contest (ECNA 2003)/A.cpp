// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228A

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string a, b;

    while (cin >> a && a != "THEEND") {
        cin >> b;
        vector <pair <int, int> > v(a.size());
        for (int i = 0; i < a.size(); i++) {
            v[i] = make_pair(a[i], i);
        }
        int r = b.size() / a.size();
        sort(v.begin(), v.end());
        string ans = b;
        for (int i = 0; i < a.size(); i++) {
            int c = v[i].second;
            for (int j = 0; j < r; j++) {
                int p = r * i + j;
                ans[j * a.size() + c] = b[p];
            }
        }
        cout << ans << "\n";
    }
}

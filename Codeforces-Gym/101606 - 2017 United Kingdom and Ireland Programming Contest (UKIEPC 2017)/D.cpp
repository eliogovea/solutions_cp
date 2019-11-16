// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606D

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    string a;
    cin >> a;
    string b = a;
    sort(b.begin(), b.end());

    vector <int> l;
    vector <int> r;

    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] == b[i]) {
                    l.push_back(j + 1);
                    r.push_back(i + 1);
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
    }

    for (int i = ((int)l.size()) - 1; i >= 0; i--) {
        cout << l[i] << " " << r[i] << "\n";
    }
}

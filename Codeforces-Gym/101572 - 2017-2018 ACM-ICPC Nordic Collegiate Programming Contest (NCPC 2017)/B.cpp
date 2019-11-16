// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572B

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    int n;
    cin >> n;

    vector <pair <double, pair <string, double> > > v(n);

    for (int i = 0; i < n; i++) {
        string s;
        double a, b;
        cin >> s >> a >> b;
        v[i].first = b;
        v[i].second.first = s;
        v[i].second.second = a;
    }

    sort(v.begin(), v.end());

    double answer_t;
    vector <string> names;

    for (int i = 0; i < n; i++) {
        double t = v[i].second.second;
        vector <string> s;
        s.push_back(v[i].second.first);
        int x = 0;
        int c = 1;
        while (c < 4) {
            if (x != i) {
                t += v[x].first;
                s.push_back(v[x].second.first);
                c++;
            }
            x++;
        }

        if (i == 0 || t < answer_t) {
            answer_t = t;
            names = s;
        }
    }

    cout.precision(10);
    cout << answer_t << "\n";
    for (int i = 0; i < 4; i++) {
        cout << names[i] << "\n";
    }
}

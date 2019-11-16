#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;
LL a[15];

vector <pair <LL, LL> > ans[15];
vector <pair <LL, LL> > okAns[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "1\n";
        cout << a[0] - 1LL << " " << a[0] + 1LL << "\n";
        return 0;
    }

    reverse(a, a + n);

    if (a[0] + 1LL < 0LL) {
        cout << "0\n";
        return 0;
    }

    ans[0].push_back(make_pair(a[0] - 1LL, a[0] + 1LL));
    for (int i = 0; i < n; i++) {
        if (!ans[i].size()) {
            cout << "0\n";
            return 0;
        }
        sort(ans[i].begin(), ans[i].end());
        LL lastL = ans[i][0].first;
        LL lastR = ans[i][0].second;
        for (int j = 1; j < ans[i].size(); j++) {
            if (ans[i][j].first > lastL) {
                if (lastR >= 0LL) {
                    okAns[i].push_back(make_pair(max(0LL, lastL), lastR));
                }
                lastL = ans[i][j].first;
                lastR = ans[i][j].second;
            } else {
                 lastR = max(lastR, ans[i][j].second);
            }
        }
        if (lastR >= 0) {
            okAns[i].push_back(make_pair(max(0LL, lastL), lastR));
        }

        if (i + 1 < n) {
            for (int j = 0; j < okAns[i].size(); j++) {
                LL l = okAns[i][j].first;
                LL r = okAns[i][j].second;
                ans[i + 1].push_back(make_pair(a[i + 1] - r, a[i + 1] - l));
                ans[i + 1].push_back(make_pair(a[i + 1] + l, a[i + 1] + r));
            }
        }
    }



    sort(ans[n - 1].begin(), ans[n - 1].end());

    LL lastL = ans[n - 1][0].first;
    LL lastR = ans[n - 1][0].second;

    vector <pair <int, int> > v;

    for (int i = 1; i < ans[n - 1].size(); i++) {
        if (ans[n - 1][i].first > lastR) {
            v.push_back(make_pair(lastL, lastR));
            lastL = ans[n - 1][i].first;
            lastR = ans[n - 1][i].second;
        } else {
            lastR = max(lastR, ans[n - 1][i].second);
        }
    }

    v.push_back(make_pair(lastL, lastR));

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}

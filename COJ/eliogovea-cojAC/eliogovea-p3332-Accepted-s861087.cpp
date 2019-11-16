#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > fa, fb;
vector<int> v;

void fact(int n, vector<pair<int, int> > &f) {
    f.clear();
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            f.push_back(make_pair(i, cnt));
        }
    }
    if (n > 1) {
        f.push_back(make_pair(n, 1));
    }
}

long long solve(int a, int b) {
        fact(a, fa);
        fact(b, fb);

        //for (int i = 0; i < fa.size(); i++) cout << fa[i].first << " " << fa[i].second << "\n"; cout << "\n";
        //for (int i = 0; i < fb.size(); i++) cout << fb[i].first << " " << fb[i].second << "\n"; cout << "\n";

        v.clear();
        for (int i = 0; i < fa.size(); i++) {
            v.push_back(fa[i].first);
        }
        for (int i = 0; i < fb.size(); i++) {
            v.push_back(fb[i].first);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        /*for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }*/
        //cout << "\n";

        long long res = 1;
        for (int i = 0; i < v.size(); i++) {
            int posa = lower_bound(fa.begin(), fa.end(), make_pair(v[i], 0)) - fa.begin();
            int posb = lower_bound(fb.begin(), fb.end(), make_pair(v[i], 0)) - fb.begin();
            int cnta = 0;
            int cntb = 0;
            if (posa < fa.size() && fa[posa].first == v[i]) cnta = fa[posa].second;
            if (posb < fb.size() && fb[posb].first == v[i]) cntb = fb[posb].second;
            //cout << v[i] << " " << cnta << " " << cntb << "\n";
            if (cnta > cntb) {
                return 0LL;
            }
            if (cntb > cnta) {
                res *= 2LL;
            }
        }
        res /= 2LL;
        return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == b) {
            cout << "1\n";
            continue;
        }
        cout << solve(a, b) << "\n";
    }
}

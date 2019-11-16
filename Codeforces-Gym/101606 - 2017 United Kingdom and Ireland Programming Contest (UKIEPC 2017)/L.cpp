// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606L

#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
};


bool operator < (const point & P, const point & Q) {
    if (P.x != Q.x) {
        return P.x < Q.x;
    }
    return P.y < Q.y;
}

bool operator != (const point & P, const point & Q) {
    return (P < Q) || (Q < P);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen( "dat.txt", "r", stdin );

    int tx, ty;
    cin >> tx >> ty;

    int n;
    cin >> n;

    vector <pair <point, pair <int, int> > > v(n);

    for (int i = 0; i < n; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        x -= tx;
        y -= ty;
        int g = __gcd(abs(x), abs(y));
        v[i].first.x = x / g;
        v[i].first.y = y / g;
        v[i].second = make_pair(g, h);
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0, j = 0; i <= n; i++) {
        if (i == n || v[i].first != v[j].first) {
            vector <pair <int, int> > vh(i - j);
            int p = 0;
            while (j < i) {
                vh[p++] = v[j++].second;
            }

            sort(vh.begin(), vh.end());

            vector <int> vl;
            for (int k = 0; k < (int)vh.size(); k++) {
                int pos = lower_bound(vl.begin(), vl.end(), vh[k].second) - vl.begin();
                if (pos == (int)vl.size()) {
                    vl.push_back(vh[k].second);
                } else {
                    vl[pos] = vh[k].second;
                }
            }

            ans += vl.size();
        }
    }

    cout << ans << "\n";
}

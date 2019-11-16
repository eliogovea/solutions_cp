// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486K

#include <bits/stdc++.h>

using namespace std;

const int N = 155;

int n, a[N][N];

vector <pair <int, int> > v;

int ans[N];

vector <int> cur;

int depth[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == i) cnt++;
        }
        depth[i] = -1;
        v.push_back(make_pair(cnt, i));
    }
    sort(v.begin(), v.end(), greater <pair <int, int> >());
    ans[v[0].second] = 0;
    depth[v[0].second] = 0;
    cur.push_back(v[0].second);
    for (int i = 1; i < n; i++) {
        int par = -1;
        int u = v[i].second;
        for (int j = 0; j < cur.size(); j++) {
            int v = cur[j];
            if (a[u][v] == v && (par == -1 || depth[par] < depth[v])) {
                par = v;
            }
        }
        ans[u] = par;
        depth[u] = depth[par] + 1;
        cur.push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i + 1 <= n) cout << " ";
    }
    cout << "\n";
}

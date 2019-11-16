// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078J

#include <bits/stdc++.h>

using namespace std;

int t;
int h, v;
string sh[555];
string sv[555];
int xh[555], yh[555], lh[555];
int xv[555], yv[555], lv[555];
vector <int> graph[555];
int match[555];

int mark[555];
int id;

bool dfs(int u) {
    if (mark[u] == id) {
        return false;
    }
    mark[u] = id;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt","r",stdin);

    cin >> t;
    while (t--) {
        cin >> h >> v;
        for (int i = 0; i < h; i++) {
            cin >> xh[i] >> yh[i] >> sh[i];
            lh[i] = sh[i].size();
        }
        for (int i = 0; i < v; i++) {
            cin >> xv[i] >> yv[i] >> sv[i];
            lv[i] = sv[i].size();
        }
        for (int i = 0; i < h; i++) {
            graph[i].clear();
            for (int j = 0; j < v; j++) {
                if (xh[i] <= xv[j] && xv[j] < xh[i] + lh[i]) {
                    if (yv[j] <= yh[i] && yh[i] < yv[j] + lv[j]) {
                        int dx = xv[j] - xh[i];
                        int dy = yh[i] - yv[j];
                        if (sh[i][dx] != sv[j][dy]) {
                            graph[i].push_back(j);
                            //cerr << i << " " << j << " " << sh[i][dx] << " " << sv[j][dy] << "\n";
                        }
                    }
                }
            }
        }
        for (int i = 0; i < v; i++) {
            match[i] = -1;
        }
        int ans = 0;
        for (int i = 0; i < h; i++) {
            id++;
            if (dfs(i)) {
                ans++;
            }
        }
        ans = h + v - ans;
        cout << ans << "\n";
    }
}

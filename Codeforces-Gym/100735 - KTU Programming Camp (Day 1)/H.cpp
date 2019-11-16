// KTU Programming Camp (Day 1)
// 100735H

#include <bits/stdc++.h>

using namespace std;

string s;
int n;
char cubes[105][10];
vector<int> g[105];
int used[105], ttt;
int match[105];

bool kuhn(int u) {
    if (used[u] == ttt) {
        return false;
    }
    used[u] = ttt;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (match[v] == -1 || kuhn(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> cubes[i][j];
        }
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (s[i] == cubes[j][k]) {
                    g[i].push_back(j);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        match[i] = -1;
    }
    for (int i = 0; i < s.size(); i++) {
        ttt++;
        if (!kuhn(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}

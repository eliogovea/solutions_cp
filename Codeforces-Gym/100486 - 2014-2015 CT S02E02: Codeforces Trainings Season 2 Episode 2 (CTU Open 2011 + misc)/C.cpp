// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486C

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int n;
string line, s;
char ans[N];

set<int> S;
set<int>::iterator it;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    while (true) {
        getline(cin, line);
        n = 0;
        for (int i = 0; line[i]; i++) {
            n = 10 * n + line[i] - '0';
        }
        if (n == 0) break;
        getline(cin, line);
        s.clear();
        S.clear();
        for (int i = 0; line[i]; i++) {
            S.insert(i);
            if (line[i] == ' ') continue;
            if (line[i] >= 'a' && line[i] <= 'z') line[i] = line[i] - 'a' + 'A';
            s += line[i];
        }
        for (int i = 0; i <= s.size(); i++) ans[i] = 0;
        int cur = 0;
        while (cur < s.size()) {
            int pos = *S.begin();
            ans[pos] = s[cur];
            S.erase(S.begin());
            cur++;
            if (pos + n < s.size()) {
                int x = pos + n;
                while (x < s.size()) {
                    it = S.find(x);
                    if (it != S.end()) {
                        ans[x] = s[cur++];
                        S.erase(it);
                    }
                    x += n;
                }
            }
        }
        cout << ans << "\n";
    }
}

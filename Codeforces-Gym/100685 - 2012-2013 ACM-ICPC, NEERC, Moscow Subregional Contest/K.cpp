// 2012-2013 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100685K

#include <bits/stdc++.h>

using namespace std;

string line;

int n;
vector <string> text, ntext;
int m;
set <string> magic;

map <string, int> words, adj;

int q;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cout.precision(10);
    getline(cin, line);
    for (int i = 0; line[i]; i++) {
        n = 10 * n + line[i] - '0';
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        string cur = "";
        for (int j = 0; j <= line.size(); j++) {
            if ((line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z')) {
                if (line[j] >= 'A' && line[j] <= 'Z') line[j] = line[j] - 'A' + 'a';
                cur += line[j];
            } else {
                if (cur.size()) {
          text.push_back(cur);
                }
                cur = "";
            }
        }
    }
    getline(cin, line);
    for (int i = 0; line[i]; i++) {
        m = 10 * m + line[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        getline(cin, line);
        for (int j = 0; line[j]; j++) {
            if (line[j] >= 'A' && line[j] <= 'Z') line[j] = line[j] - 'A' + 'a';
        }
        magic.insert(line);
    }

    for (int i = 0; i < text.size(); i++) {
        if (magic.find(text[i]) == magic.end()) {
            ntext.push_back(text[i]);
            words[text[i]]++;
            total++;
        }
    }

    int cnt_adj = total - 1;

    for (int i = 0; i + 1 < ntext.size(); i++) {
        string tmp = "";
        if (ntext[i] < ntext[i + 1]) {
            tmp = ntext[i] + " " + ntext[i + 1];
        } else {
            tmp = ntext[i + 1] + " " + ntext[i];
        }
        adj[tmp]++;
    }


    getline(cin, line);
    for (int i = 0; line[i]; i++) {
        q = 10 * q + line[i] - '0';
    }
    while (q--) {
        getline(cin, line);
        int pos = -1;
        for (int i = 0; line[i]; i++) {
            if (line[i] == ' ') {
                pos = i;
                break;
            }
        }
        if (pos == -1) pos = line.size();
        a.clear();
        b.clear();
        for (int i = 0; i < pos; i++) a += line[i];
        for (int i = pos + 1; line[i]; i++) b += line[i];
        if (a > b) swap(a, b);
        if (words.find(a) == words.end() || words.find(b) == words.end()) {
            cout << "0\n";
            continue;
        }
        double cntab = adj[a + " " + b];
        double cnta = words[a];
        double cntb = words[b];
        double ans = cntab * total * total / cnta / cntb / (double)cnt_adj;
        cout << fixed << ans << "\n";
    }
}

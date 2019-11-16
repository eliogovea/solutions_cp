// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801H

#include <bits/stdc++.h>

using namespace std;

string ans[1005];

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);


    string alph;
    for (char i = 'a'; i <= 'z'; i++) alph += i;
    for (char i = 'A'; i <= 'Z'; i++) alph += i;
    map <int, vector <string> > cnt;
    for (int i = 0; i < alph.size(); i++) {
        for (int j = 0; j < alph.size(); j++) {
            int hash = 31 * alph[i] + alph[j];
            string tmp; tmp += alph[i]; tmp += alph[j];
            cnt[hash].push_back(tmp);
        }
    }
    vector <pair <string, string> > v;
    for (map <int , vector <string> >::iterator it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second.size() > 1) {
            for (int i = 0; i < it->second.size(); i++) {
                v.push_back(make_pair(it->second[0], it->second[1]));
            }
        }
    }
    int k;
    cin >> k;
    int x = 0;
    while ((1 << x) < k) x++;
    for (int i = 0; i < k && i < (1 << x); i++) {
        string tmp;
        for (int j = 0; j < x; j++) {
            if (i & (1 << j)) {
                tmp += v[j].first;
            } else {
                tmp += v[j].second;
            }
        }
        //int hash = 0;
        //for (int i = 0; tmp[i]; i++) hash = 31 * hash + tmp[i];
        cout << tmp << "\n";
    }
}

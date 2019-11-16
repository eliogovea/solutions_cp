#include <bits/stdc++.h>

using namespace std;


inline string LLToString(long long n) {
    if (n == 0) {
        return "0";
    }
    string res;
    while (n) {
        res += '0' + (n % 10LL);
        n /= 10LL;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long INF = numeric_limits <long long> :: max();
    vector <long long> f;
    vector <string> fs;
    f.push_back(1);
    f.push_back(1);
    fs.push_back("1");
    fs.push_back("1");
    int size = 2;
    while (true) {
        if (f[size - 1] <= INF - f[size - 2]) {
            f.push_back(f[size - 1] + f[size - 2]);
            fs.push_back(LLToString(f.back()));
            size++;
        } else {
            break;
        }
    }
    // cerr << size << "\n";
    vector <string> cf;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                cf.push_back(fs[i] + fs[j]);
            }
        }
    }
    sort(cf.begin(), cf.end());
    cf.erase(unique(cf.begin(), cf.end()), cf.end());
    vector <vector <bool> > ok(size, vector <bool> (size));
    vector <bool> used(cf.size());
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                int pos = lower_bound(cf.begin(), cf.end(), fs[i] + fs[j]) - cf.begin();
                if (!used[pos]) {
                    used[pos] = true;
                    ok[i][j] = true;
                }
            }
        }
    }
    // cerr << cf.size() << "\n";
    string s;
    while (cin >> s) {
        vector <int> okl(size, -1);
        for (int i = 0; i < size; i++) {
            int pos = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == fs[i][pos]) {
                    pos++;
                    if (pos == fs[i].size()) {
                        okl[i] = j;
                        break;
                    }
                }
            }
        }
        vector <int> okr(size, -1);
        for (int i = 0; i < size; i++) {
            int pos = fs[i].size() - 1;
            for (int j = ((int)s.size()) - 1; j >= 0; j--) {
                if (s[j] == fs[i][pos]) {
                    pos--;
                    if (pos == -1) {
                        okr[i] = j;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (okl[i] == -1){
                continue;
            }
            for (int j = 0; j < size; j++) {
                if (i != j && ok[i][j]) {
                    if (okr[j] != -1 && okl[i] < okr[j]) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

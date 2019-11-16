// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095N

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string s, n;
    while (cin >> s && s[0] != 'e') {
        cin >> n;
        if (n == "0") {
            cout << "0\n";
            continue;
        }
        if (s[0] == 't') {
            int b = 0;
            for (int i = 3; i < s.size(); i++) {
                b = 10 * b + (s[i] - '0');
            }
            bool neg = (n[0] == '-');
            int val = 0;
            for (int i = neg; i < n.size(); i++) {
                val = 10 * val + (n[i] - '0');
            }

            vector <int> v;
            while (val) {
                v.push_back(val % b);
                val /= b;
            }
            v.push_back(0);
            v.push_back(0);
            v.push_back(0);

            vector <int> d(v.size(), 0);

            if (!neg) {
                int carry = 0;
                for (int i = 0; i < v.size(); i++) {
                    carry += v[i];
                    if (!(i & 1)) {
                        d[i] = carry % b;
                    } else {
                        if ((carry % b) != 0) {
                            d[i] = b - (carry % b);
                        }
                        carry += d[i];
                    }
                    carry /= b;
                }
            } else {
                int carry = 0;
                for (int i = 0; i < v.size(); i++) {
                    carry += v[i];
                    if (i & 1) {
                        d[i] = carry % b;
                    } else {
                        if ((carry % b) != 0) {
                            d[i] = b - (carry % b);
                        }
                        carry += d[i];
                    }
                    carry /= b;
                }
            }


            int pos = v.size() - 1;
            while (d[pos] == 0) {
                pos--;
            }
            while (pos >= 0) {
                cout << d[pos];
                pos--;
            }
            cout << "\n";
        } else {
            long long b = 0;
            for (int i = 5; i < s.size(); i++) {
                b = 10LL  * b + (s[i] - '0');
            }
            bool neg = (n[0] == '0');
            long long ans = 0;
            for (int i = neg; i < n.size(); i++) {
                ans = (-b) * ans + (long long)(n[i] - '0');
            }
            cout << ans << "\n";
        }
    }
}

// 2015-2016 Petrozavodsk Winter Training Camp, Nizhny Novgorod SU Contest
// 100960B

#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 5;

int n, xs;
int x[N], y[N];
int id[N];

set <pair <int, int> > S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> xs;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> id[i];
        y[i] = x[i];
        S.insert(make_pair(x[i], id[i]));
    }
    set <pair <int, int> > :: iterator now;
    int dir = 0;
    int ans = 0;
    if (S.begin()->first > xs) {
        ans = 1;
        dir = 1;
        now = S.begin();
    } else {
        now = --S.upper_bound(make_pair(xs, 1));
        dir = 0;
    }
    while (true) {
        if (dir == 0) {
            while (now != S.begin() && now->second != dir) {
                now--;
            }
            if (now->second != dir) {
                //cerr << "case 1\n";
                ans++;
            } else {
                set <pair <int, int> > :: iterator next = now;
                next++;
                if (next == S.end()) {
                    S.erase(now);
                    break;
                }
                S.erase(now);
                now = next;
            }
            dir = 1;
        } else {
            while (now != S.end() && now->second != dir) {
                now++;
            }
            if (now == S.end()) {
                break;
            } else {
                if (now == S.begin()) {
                    set <pair <int, int> > :: iterator next = now;
                    //cerr << "case 2\n";
                    ans++;
                    next++;
                    S.erase(now);
                    now = next;
                    if (now == S.end()) {
                        break;
                    }
                } else {
                    set <pair <int, int> > :: iterator next = now;
                    next--;
                    S.erase(now);
                    now = next;
                    if (now == S.end()) {
                        break;
                    }
                    dir = 0;
                }

            }
        }
    }
    if (S.size()) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
}

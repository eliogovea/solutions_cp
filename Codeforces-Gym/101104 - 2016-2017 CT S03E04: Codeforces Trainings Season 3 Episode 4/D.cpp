// 2016-2017 CT S03E04: Codeforces Trainings Season 3 Episode 4
// 101104D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void add(vector <int> &f, int &mask, int d) {
    f[d]++;
    if (f[d] == 1) {
        mask |= (1 << d);
    }
}

inline void remove(vector <int> &f, int  &mask, int d) {
    f[d]--;
    if (f[d] == 0) {
        mask ^= (1 << d);
    }
}

int solve(string a, string b) {
    string aa = a;
    string bb = b;
    vector <int> fa(10, 0), fb(10, 0);
    int sa = a.size();
    int sb = b.size();
    for (int i = 0; i < sa; i++) {
        a[i] -= '0';
        fa[a[i]]++;
    }
    for (int i = 0; i < sb; i++) {
        b[i] -= '0';
        fb[b[i]]++;
    }
    int maska = 0;
    int maskb = 0;
    for (int i = 0; i < 10; i++) {
        if (fa[i]) {
            maska |= (1 << i);
        }
        if (fb[i]) {
            maskb |= (1 << i);
        }
    }
    if (maska == maskb) {
        return 0; // f
    }
    for (int i = 0; i + 1 < sa; i++) {
        if ((i == 0 && a[i] >= 2) || (i > 0 && a[i] >= 1)) {
            if (a[i + 1] < 9) {
                remove(fa, maska, a[i]);
                add(fa, maska, a[i] - 1);
                remove(fa, maska, a[i + 1]);
                add(fa, maska, a[i + 1] + 1);
                if (maska == maskb) {
                    return 1;
                }
                remove(fa, maska, a[i + 1] + 1);
                add(fa, maska, a[i + 1]);
                remove(fa, maska, a[i] - 1);
                add(fa, maska, a[i]);
            }
        }
        if (a[i] < 9 && a[i + 1] > 0) {
            remove(fa, maska, a[i]);
            add(fa, maska, a[i] + 1);
            remove(fa, maska, a[i + 1]);
            add(fa, maska, a[i + 1] - 1);

            if (maska == maskb) {
                return 1;
            }
            remove(fa, maska, a[i + 1] - 1);
            add(fa, maska, a[i + 1]);
            remove(fa, maska, a[i] + 1);
            add(fa, maska, a[i]);
        }
    }
    return 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int ansAB = solve(a, b);
        if (ansAB == 0) {
            cout << "friends\n";
            continue;
        }
        int ansBA = solve(b, a);
        if (min(ansAB, ansBA) == 1) {
            cout << "almost friends\n";
        } else {
            cout << "nothing\n";
        }
    }
}

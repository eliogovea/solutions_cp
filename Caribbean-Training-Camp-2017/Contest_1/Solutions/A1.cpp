#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int n, l;
LL w[500 * 1000 + 10];
LL e[500 * 1000 + 10],  v[500 * 1000 + 10];

int bit[500 * 1000 + 10];

inline void update(int p, int n, int v) {
    while (p <= n) {
        bit[p] += v;
        p += p & -p;
    }
}

inline int query(int p) {
    int res = 0;
    while (p > 0) {
        res += bit[p];
        p -= p & -p;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> l;


    for (int i = 0; i < n; i++) {
        cin >> w[i];
        e[i] = l * w[i] + (long long)i;
        v[i] = e[i];
    }

    sort(v, v + n);
    int cnt = unique(v, v + n) - v;


    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(v, v + cnt, e[i]) - v + 1;
        ans += (long long)(i - query(pos));
        update(pos, cnt, 1);
    }

    cout << ans << "\n";
}

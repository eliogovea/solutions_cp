// KTU Programming Camp (Day 5)
// 100741A

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int n, m;

struct data {
    int leaf;
    long long sum[10];
    data() {
        leaf = -1;
        for (int i = 0; i < m; i++) {
            sum[i] = 0;
        }
    }
};

data operator + (const data &a, const data &b) {
    data res;
    res = data();
    for (int i = 0; i < m; i++) {
        res.sum[i] = a.sum[i] + b.sum[i];
    }
    return res;
}

int arr[N];
data t[4 * N];

void build(int x, int l, int r) {
    if (l == r) {
        t[x].leaf = arr[l] % m;
        t[x].sum[arr[l] % m] = arr[l];
    } else {
        int m = (l + r) >> 1;
        build(x + x, l, m);
        build(x + x + 1, m + 1, r);
        t[x] = t[x + x] + t[x + x + 1];
    }
}

void update(int x, int l, int r, int p, int v, int sign) {
    if (p < l || p > r) {
        return;
    }
    if (l == r) {
        long long old = t[x].sum[t[x].leaf];
        if (old + sign * v < 0) {
            cout << t[x].sum[t[x].leaf] << "\n";
            return;
        }
        t[x].sum[t[x].leaf] = 0;
        t[x].leaf = (old + ((sign * v) % m) + m) % m;
        if (t[x].leaf < 0) {
            t[x].leaf += m;
        }
        t[x].sum[t[x].leaf] = old + sign * v;
        cout << t[x].sum[t[x].leaf] << "\n";
    } else {
        int m = (l + r) >> 1;
        update(x + x, l, m, p, v, sign);
        update(x + x + 1, m + 1, r, p, v, sign);
        t[x] = t[x + x] + t[x + x + 1];
    }
}

long long query(int x, int l, int r, int ql, int qr, int mod) {
    if (l > qr || r < ql) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return t[x].sum[mod];
    }
    int m = (l + r) >> 1;
    long long q1 = query(x + x, l, m, ql, qr, mod);
    long long q2 = query(x + x + 1, m + 1, r, ql, qr, mod);
    return q1 + q2;
}

int q;
char ty;
int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> ty;
        if (ty == 's') {
            cin >> a >> b >> c;
            cout << query(1, 1, n, a, b, c) << "\n";
        } else {
            cin >> a >> b;
            update(1, 1, n, a, b, ty == '+' ? 1 : -1);
        }
    }
}

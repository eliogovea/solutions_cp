#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000;
const long long INF = 1e18;

int n;
long long a[N + 10];
long long st[4 * N + 10];
long long lazy[4 * N + 10];

void build(int x, int l, int r) {
    lazy[x] = 0;
    if (l == r) {
        st[x] = a[l];
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = max(st[2 * x], st[2 * x + 1]);
    }
}

inline void push(int x, int l, int r) {
    if (lazy[x] > 0) {
        st[x] += lazy[x];
        if (l != r) {
            lazy[2 * x] += lazy[x];
            lazy[2 * x + 1] += lazy[x];
        }
        lazy[x] = 0;
    }
}

void update(int x, int l, int r, int ul, int ur, int v) {
    push(x, l, r);
    if (l > ur || r < ul) {
        return;
    }
    if (l >= ul && r <= ur) {
        lazy[x] += v;
        push(x, l, r);
    } else {
        int m = (l + r) >> 1;
        update(2 * x, l, m, ul, ur, v);
        update(2 * x + 1, m + 1, r, ul, ur, v);
        st[x] = max(st[2 * x], st[2 * x + 1]);
    }
}

long long query(int x, int l, int r, int ql, int qr) {
    push(x, l, r);
    if (l > qr || r < ql) {
        return -INF;
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int m = (l + r) >> 1;
    return max(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        char o;
        cin >> o;
        if (o == 'm') {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }

}


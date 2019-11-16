#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000;
const int INF = 1e9;

int a[N + 10];
pair <int, int> st[4 * N + 10];

pair <int, int> add(const pair <int, int> & a, const pair <int, int> & b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void build(int x, int l, int r) {
    if (l == r) {
        st[x] = make_pair(a[l], a[l]);
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = add(st[2 * x], st[2 * x + 1]);
    }
}

void update(int x, int l, int r, int p, int v) {
    if (p < l || r < p) {
        return;
    }
    if (l == r) {
        st[x] = make_pair(v, v);
    } else {
        int m = (l + r) >> 1;
        update(2 * x, l, m, p, v);
        update(2 * x + 1, m + 1, r, p, v);
        st[x] = add(st[2 * x], st[2 * x + 1]);
    }
}

pair <int, int> query(int x, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return make_pair(INF, -INF);
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int m = (l + r) >> 1;
    return add(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}

const int M1 = 12345;
const int M2 = 23456;

int gen(long long x) {
    int a = x * x % M1;
    int b = ((x * x % M2) * x) % M2;
    return a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    for (int i = 1; i <= N; i++) {
        a[i] = gen(i);
    }

    build(1, 1, N);
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;

        if (l > 0) {
            pair <int, int> ans = query(1, 1, N, l, r);
            cout << ans.second - ans.first << "\n";
        } else {
            update(1, 1, N, -l, r);
        }
    }
}

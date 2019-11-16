#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

int n;
int a[N];
int st[4 * N];

void build(int x, int l, int r) {
    if (l == r) {
        st[x] = a[l];
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = __gcd(st[2 * x], st[2 * x + 1]);
    }
}

int query(int x, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int m = (l + r) >> 1;
    return __gcd(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << "\n";
    }
}

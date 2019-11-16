#include <bits/stdc++.h>

using namespace std;

struct node {
    bool isNull;
    int res, l, r;
    node() {
        isNull = true;
        res = l = r = 0;
    }
};

node add(const node & a, const node & b) {
    if (a.isNull) {
        return b;
    }
    if (b.isNull) {
        return a;
    }
    node res;
    res.isNull = false;
    res.l = max(a.l - b.r, 0) + b.l;
    res.r = max(b.r - a.l, 0) + a.r;
    res.res = a.res + b.res + 2 * min(a.l, b.r);
    return res;
}

const int N = 1000 * 1000 + 5;

node st[4 * N];
string s;

void build(int x, int l, int r) {
    if (l == r) {
        st[x].isNull = false;
        if (s[l - 1] == '(') {
            st[x].l = 1;
        } else {
            st[x].r = 1;
        }

    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = add(st[2 * x], st[2 * x + 1]);
    }

    // cerr << x << " " << l << " " << r << " -> " << st[x].isNull << " " << st[x].res << " " << st[x].l << " " << st[x].r << "\n";
}

node query(int x, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return node();
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int m = (l + r) >> 1;
    return add(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    cin >> s;

    build(1, 1, s.size());

    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, s.size(), l, r).res << "\n";
    }
}

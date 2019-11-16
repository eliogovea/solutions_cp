#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

const int N = 100005;

struct data {
    int pos;
    int l;
    vector <long long> v;
    data() {}
    data(long long x) {
        pos = 0;
        l = 1;
        while (x > 1) {
            v.push_back(x);
            x = (long long)sqrt(x);
        }
        v.push_back(1);
    }
};

data merge(data &a, data &b) {
    data res;
    res.pos = 0;
    res.l = a.l + b.l;
    res.v.clear();
    for (int i = 0; i + a.pos < a.v.size() || i + b.pos < b.v.size(); i++) {
        long long val = 0;
        if (i + a.pos < a.v.size()) {
            val += a.v[i + a.pos];
        } else {
            val += a.l;
        }
        if (i + b.pos < b.v.size()) {
            val += b.v[i + b.pos];
        } else {
            val += b.l;
        }
        res.v.push_back(val);
    }
    return res;
}

int n, q;
long long a[N];

data st[4 * N];
int lazy[4 * N];

void build(int x, int l, int r) {
    if (l == r) {
        st[x] = data(a[l]);
    } else {
        int mid = (l + r) >> 1;
        build(2 * x, l, mid);
        build(2 * x + 1, mid + 1, r);
        st[x] = merge(st[2 * x], st[2 * x + 1]);
    }
}

inline void push(int x, int l, int r) {
    if (lazy[x] > 0) {
        st[x].pos += lazy[x];
        if (st[x].pos >= st[x].v.size()) {
            st[x].pos = st[x].v.size() - 1;
        }
        if (l != r) {
            lazy[2 * x] += lazy[x];
            lazy[2 * x + 1] += lazy[x];
        }
        lazy[x] = 0;
    }
}

void update1(int x, int l, int r, int ul, int ur) {
    push(x, l, r);
    if (l > ur || r < ul) {
        return;
    }
    if (l >= ul && r <= ur) {
        lazy[x]++;
        push(x, l, r);
    } else {
        int mid = (l + r) >> 1;
        update1(2 * x, l, mid, ul, ur);
        update1(2 * x + 1, mid + 1, r, ul, ur);
        st[x] = merge(st[2 * x], st[2 * x + 1]);
    }
}

void update2(int x, int l, int r, int p, long long v) {
    push(x, l, r);
    if (p > r || p < l) {
        return;
    }
    if (l == r) {
        st[x] = data(v);
    } else {
        int mid = (l + r) >> 1;
        update2(2 * x, l, mid, p, v);
        update2(2 * x + 1, mid + 1, r, p, v);
        st[x] = merge(st[2 * x], st[2 * x + 1]);
    }
}

long long query(int x, int l, int r, int ql, int qr) {
    push(x, l, r);
    if (l > qr || r < ql) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return st[x].v[st[x].pos];
    }
    int mid = (l + r) >> 1;
    long long q1 = query(2 * x, l, mid, ql, qr);
    long long q2 = query(2 * x + 1, mid + 1, r, ql, qr);
    return q1 + q2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen(""dat.txt"", ""r"", stdin);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int x, y, z;
    while (q--) {
        cin >> x >> y >> z;
        if (x == 1) {
            update1(1, 1, n, y, z);
        } else if (x == 2) {
            update2(1, 1, n, y, z);
        } else {
            cout << query(1, 1, n, y, z) << "\n";
        }
    }
}

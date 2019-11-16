#include <bits/stdc++.h>

using namespace std;

const int N = 10 * 1000 + 10;

pair <int, int> st[4 * N];
int lazy[4 * N];

inline pair <int, int> add(const pair <int, int> & a, const pair <int, int> & b) {
    if (a.first > b.first) {
        return a;
    }
    return b;
}

void build(int x, int l, int r) {
    lazy[x] = 0;
    if (l == r) {
        st[x] = make_pair(0, l);
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = add(st[2 * x], st[2 * x + 1]);
    }
}

inline void push(int x, int l, int r) {
    if (lazy[x] != 0) {
        st[x].first += lazy[x];
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
        st[x] = add(st[2 * x], st[2 * x + 1]);
    }
}

const int INF = 1e9;

pair <int, int> query(int x, int l, int r, int ql, int qr) {
    push(x, l, r);
    if (l > qr || r < ql) {
        return make_pair(0, 0);
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int m = (l + r) >> 1;
    return add(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
}

int n, k;
pair <int, int> pts[50 * 1000 + 10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    sort(pts, pts + n);

    const int Y = 10 * 1000;

    int lo = 1;
    int hi = 10 * 1000;

    int res = -1;
    int ansx;
    int ansy;

    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        build(1, 1, Y);

        bool ok = false;

        for (int i = 0, j = 0; i < n; i++) {
            update(1, 1, Y, max(pts[i].second - mid, 1), pts[i].second, 1);
            while (j < i && pts[j].first < pts[i].first - mid) {
                update(1, 1, Y, max(pts[j].second - mid, 1), pts[j].second, -1);
                j++;
            }
            push(1, 1, Y);
            if (st[1].first >= k) {
                ok = true;

                cerr << "__ " << mid << " " << i << " " << st[1].first << "\n";

                if (res == -1 || res > mid) {
                    res = mid;
                    ansx = pts[i].first - mid;
                    ansy = st[1].second;
                }
                break;
            }
        }

        if (!ok) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    assert(res != -1);

    cout << res << "\n";
    cout << ansx << " " << ansy << "\n";
}

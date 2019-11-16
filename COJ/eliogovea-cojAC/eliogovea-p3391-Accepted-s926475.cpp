#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, r;
int s[N];

int to[N];

int st[4 * N];

void build(int x, int l, int r) {
    if (l == r) {
        st[x] = to[l];
    } else {
        int mid = (l + r) >> 1;
        build(2 * x, l, mid);
        build(2 * x + 1, mid + 1, r);
        st[x] = max(st[2 * x], st[2 * x + 1]);
    }
}

void update(int x, int l, int r, int p, int v) {
    if (p < l || p > r) {
        return;
    }
    if (l == r) {
        st[x] = v;
    } else {
        int mid = (l + r) >> 1;
        update(2 * x, l, mid, p, v);
        update(2 * x + 1, mid + 1, r, p, v);
        st[x] = max(st[2 * x], st[2 * x + 1]);
    }
}

int query(int x, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return st[x];
    }
    int mid = (l + r) >> 1;
    int q1 = query(2 * x, l, mid, ql, qr);
    int q2 = query(2 * x + 1, mid + 1, r, ql, qr);
    return max(q1, q2);
}

map <int, set <int> >  M;
map <int, set <int> >::iterator it;
set <int> ::iterator itt;

int last[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        to[i] = last[s[i]];
        last[s[i]] = i;
        M[s[i]].insert(i);
    }
    to[0] = -1;

    build(1, 0, n);

    while (r--) {
        char c;
        cin >> c;
        if (c == 'C') {
            int x, y;
            cin >> x >> y;

            if (s[x] == y) {
                continue;
            }


            set <int> &S = M.find(s[x])->second;

            itt = S.find(x);

            if (S.size() == 1) {
                S.clear();
            } else {
                if (itt == S.begin()) {
                    set <int> ::iterator a = itt; a++;
                    update(1, 0, n, *a, 0);
                    S.erase(itt);
                } else {
                    set <int>::iterator a = itt; a++;
                    if (a == S.end()) {
                        S.erase(itt);
                    } else {
                        set <int>::iterator b = itt; b--;
                        update(1, 0, n, *a, *b);
                        S.erase(itt);
                    }
                }
            }

            if (S.size() == 0) {
                M.erase(M.find(s[x]));
            }

            //insert
            s[x] = y;
            if (M.find(s[x]) == M.end()) {
                M[s[x]];
            }
            set <int> &SS = M.find(s[x])->second;
            SS.insert(x);
            itt = SS.find(x);
            if (SS.size() == 1) {
                update(1, 0, n, x, 0);
            } else {
                if (itt == SS.begin()) {
                    set <int> ::iterator a = itt; a++;
                    update(1, 0, n, x, 0);
                    update(1, 0, n, *a, x);
                } else {
                    set <int> ::iterator a = itt; a++;
                    if (a == SS.end()) {
                        set <int> ::iterator b = itt; b--;
                        update(1, 0, n, x, *b);
                    } else {
                        set <int>::iterator b = itt; b--;
                        update(1, 0, n, x, *b);
                        update(1, 0, n, *a, x);
                    }
                }
            }
        } else {
            int x;
            cin >> x;
            int lo = 0;
            int hi = x - 1;
            int ans = x - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (query(1, 0, n, mid + 1, x) <= mid) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            cout << x - ans << "\n";
        }
    }
}

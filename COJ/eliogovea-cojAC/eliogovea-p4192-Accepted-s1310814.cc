#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

int n, p, s;
int v[N];
int id[N], q_l[N], q_r[N];

int cnt_0[4 * N];
int cnt_1[4 * N];

int cnt[N];
int sum[N];

void update(int *cnt, int x, int l, int r, int p, int v)  {
    if (p < l || r < p) {
        return;
    }
    if (l == r) {
        cnt[x] = v;
    } else {
        int m = (l + r) >> 1;
        update(cnt, 2 * x, l, m, p, v);
        update(cnt, 2 * x + 1, m + 1, r, p, v);
        cnt[x] = cnt[2 * x] + cnt[2 * x + 1];
    }
}

int query(int *cnt, int x, int l, int r, int ql, int qr) {
    if (qr < ql || l > qr || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return cnt[x];
    }
    int m = (l + r) >> 1;
    return query(cnt, 2 * x, l, m, ql, qr) + query(cnt, 2 * x + 1, m + 1, r, ql, qr);
}

int last_one(int *cnt) {
    int x = 1;
    int l = 0;
    int r = s - 1;

    if (cnt[x] == 0) {
        return -1;
    }

    while (l < r) {
        int m = (l + r) >> 1;
        if (cnt[2 * x + 1] > 0) {
            x = 2 * x + 1;
            l = m + 1;
        } else {
            x = 2 * x;
            r = m;
        }
    }
    return l;
}

int find_kth(int *cnt, int k) {
    int x = 1;
    if (cnt[x] < k) {
        return -1;
    }
    int l = 0;
    int r = s - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (cnt[2 * x] >= k) {
            x = 2 * x;
            r = m;
        } else {
            k -= cnt[2 * x];
            x = 2 * x + 1;
            l = m + 1;
        }
    }
    return l;
}

struct event {
    int card_id;
    int type;
    int query_time;
    int who;

    event() {}
    event(int _card_id, int _type, int _query_time, int _who) : card_id(_card_id), type(_type), query_time(_query_time), who(_who) {}

};

bool operator < (const event & lhs, const event & rhs) {
    if (lhs.card_id != rhs.card_id) {
        return lhs.card_id < rhs.card_id; 
    }
    return lhs.type < rhs.type;
}

event events[3 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> s;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < s; i++) {
        cin >> id[i] >> q_l[i] >> q_r[i];
    }

    int e = 0;

    for (int i = 1; i <= n; i++) {
        events[e++] = event(i, 0, -1, -1);
    }

    for (int i = 0; i < s; i++) {
        events[e++] = event(q_l[i], -1, i, id[i]);
        events[e++] = event(q_r[i], 1, i, id[i]);
    }

    sort(events, events + e);

    for (int i = 0; i < e; i++) {
        if (events[i].type == 0) {
            int x = last_one(cnt_0);
            int c = query(cnt_1, 1, 0, s - 1, 0, x);
            int y = find_kth(cnt_1, c + 1);

            if (y == -1) {
                continue;
            }

            assert(y > x);

            int z = id[y];
            assert(z > 0);

            cnt[z]++;
            sum[z] += v[events[i].card_id];
                
        } else if (events[i].type == -1) {
            if (events[i].who == 0) {
                update(cnt_0, 1, 0, s - 1, events[i].query_time, 1);
            } else {
                update(cnt_1, 1, 0, s - 1, events[i].query_time, 1);
            }
        } else {
            if (events[i].who == 0) {
                update(cnt_0, 1, 0, s - 1, events[i].query_time, 0);
            } else {
                update(cnt_1, 1, 0, s - 1, events[i].query_time, 0);
            }
        }
    }

    vector <int> order(p);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(), [&](int i, int j) {
            if (sum[i] != sum[j]) {
                return sum[i] > sum[j];
            }
            if (cnt[i] != cnt[j]) {
                return cnt[i] < cnt[j];
            }
            return i < j;
    });

    for (auto x : order) {
        if (cnt[x] == 0) {
            break;
        }
        cout << x << " " << sum[x] << " " << cnt[x] << "\n";
    }

}

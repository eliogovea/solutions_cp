// Problem: pace=1&num=1989
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

template <int N, int B, int P>
struct hashSegmentTree {
    int power[N + 1];

    inline int value(char c) {
        return c - 'a' + 1;
    }

    struct node {
        bool isNull;
        int length;
        int hash;

        node() : isNull(true), length(0), hash(0) {}
        node(int _hash) : isNull(false), length(1), hash(_hash) {}

    } tree[4 * N + 20];

    node merge(node lhs, node rhs) {
        if (lhs.isNull) {
            return rhs;
        }
        if (rhs.isNull) {
            return lhs;
        }
        node res;
        res.isNull = false;
        res.length = lhs.length + rhs.length;
        res.hash = ((long long)lhs.hash * power[rhs.length] % P) + rhs.hash;
        if (res.hash >= P) {
            res.hash -= P;
        }
        return res;
    }

    hashSegmentTree() {
        power[0] = 1;
        for (int i = 1; i <= N; i++) {
            power[i] = (long long)power[i - 1] * B % P;
        }
    }

    void update(int id, int left, int right, int pos, int val) {
        if (left == right) {
            tree[id] = node(val);
        } else {
            int middle = (left + right) >> 1;
            if (pos <= middle) {
                update(2 * id, left, middle, pos, val);
            } else {
                update(2 * id + 1, middle + 1, right, pos, val);
            }
            tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
        }
    }

    void update(int pos, int val) {
        update(1, 1, N, pos, val);
    }

    node query(int id, int left, int right, int from, int to) {
        // cerr << "query: " << id << " " << left << " " << right << " " << from << " " << to << "\n";
        if (right < from || to < left) {
            return node();
        }
        if (from <= left && right <= to) {
            return tree[id];
        }
        int middle = (left + right) >> 1;
        return merge(query(2 * id, left, middle, from, to), query(2 * id + 1, middle + 1, right, from, to));
    }

    int query(int from, int to) {
        return query(1, 1, N, from, to).hash;
    } 
};

inline int value(char c) {
    return c - 'a' + 1;
}

const int N = 100 * 1000;
auto st11 = hashSegmentTree <N, 37, 1000 * 1000 * 1000 + 7> ();
auto st12 = hashSegmentTree <N, 37, 1000 * 1000 * 1000 + 7> ();
auto st21 = hashSegmentTree <N, 41, 1000 * 1000 * 1000 + 9> ();
auto st22 = hashSegmentTree <N, 41, 1000 * 1000 * 1000 + 9> ();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    string s;
    cin >> s;

    string rs = s;
    reverse(rs.begin(), rs.end());

    int n = s.size();

    for (int i = 0; i < n; i++) {
        st11.update(i + 1, st11.value(s[i]));
        st12.update(n - i, st12.value(s[i]));

        st21.update(i + 1, st21.value(s[i]));
        st22.update(n - i, st22.value(s[i]));
    }

    int nq;
    cin >> nq;

    while (nq--) {
        string op;
        cin >> op;

        if (op[0] == 'p') {
            int l, r;
            cin >> l >> r;

            int hash11 = st11.query(l, r);
            int hash12 = st12.query(n + 1 - r, n + 1 - l);

            if (hash11 != hash12) {
                cout << "No\n";
                continue;
            }

            int hash21 = st21.query(l, r);
            int hash22 = st22.query(n + 1 - r, n + 1 - l);

            if (hash21 != hash22) {
                cout << "No\n";
                continue;
            }

            cout << "Yes\n";
        } else {
            int p;
            char c;

            cin >> p >> c;

            st11.update(p, value(c));
            st12.update(n + 1 - p, value(c));
            st21.update(p, value(c));
            st22.update(n + 1 - p, value(c));
        }
    }
}

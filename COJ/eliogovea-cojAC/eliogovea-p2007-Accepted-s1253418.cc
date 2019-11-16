// http://www.usaco.org/index.php?page=viewproblem2&cpid=138

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct segmentTree {
    int n;
    vector <long long> tree;
    vector <long long> toAdd;

    segmentTree(int _n) : n(_n), tree(4 * n), toAdd(4 * n) {}

    void push(int x, int l, int r) {
        if (toAdd[x] != 0) {
            tree[x] += toAdd[x];
            if (l != r) {
                toAdd[2 * x] += toAdd[x];
                toAdd[2 * x + 1] += toAdd[x];
            }
            toAdd[x] = 0;
        }
    }

    void updateSet(int x, int l, int r, int p, long long v) {
        push(x, l, r);
        if (p < l || r < p) {
            return;
        }
        if (l == r) {
            tree[x] = v;
        } else {
            int m = (l + r) >> 1;
            updateSet(2 * x, l, m, p, v);
            updateSet(2 * x + 1, m + 1, r, p, v);
            tree[x] = min(tree[2 * x], tree[2 * x + 1]);
        }
    }

    void updateSet(int p, long long v) {
        updateSet(1, 0, n, p, v);
    }

    void updateAdd(int x, int l, int r, int ql, int qr, long long v) {
        push(x, l, r);
        if (r < ql || qr < l) {
            return;
        }
        if (ql <= l && r <= qr) {
            toAdd[x] += v;
            push(x, l, r);
        } else {
            int m = (l + r) >> 1;
            updateAdd(2 * x, l, m, ql, qr, v);
            updateAdd(2 * x + 1, m + 1, r, ql, qr, v);
            tree[x] = min(tree[2 * x], tree[2 * x + 1]);
        }
    }

    void updateAdd(int ql, int qr, long long v) {
        return updateAdd(1, 0, n, ql, qr, v);
    }

    long long query(int x, int l, int r, int ql, int qr) {
        push(x, l, r);
        if (r < ql || qr < l) {
            return 1e17;
        }
        if (ql <= l && r <= qr) {
            return tree[x];
        }
        int m = (l + r) >> 1;
        return min(query(2 * x, l, m, ql, qr), query(2 * x + 1, m + 1, r, ql, qr));
    }

    long long query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l;

    cin >> n >> l;

    vector <int> h(n + 1), w(n + 1);

    h[0] = 1e9; // infinity
    w[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
    }

    vector <long long> dp(n + 1);
    segmentTree st(n + 1);

    st.updateSet(0, 0);

    vector <int> _stack(n + 1);
    int top = 0;

    _stack[top++] = 0;

    long long sumw = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        // cerr << "start " << i << "\n";

        sumw += w[i];
        while (sumw > l) {
            sumw -= w[j];
            j++;
        }

        dp[i] = 1e18;

        // update
        assert(_stack[top - 1] == i - 1);

        st.updateAdd(i - 1, i - 1, h[i]); /// last postition !!!

        while (h[_stack[top - 1]] <= h[i]) {
            st.updateAdd(_stack[top - 2], _stack[top - 1] - 1, h[i] - h[_stack[top - 1]]);

            // cerr << "update interval [" << _stack[top - 2] << ", " << _stack[top - 1] << ") " << h[i] - h[_stack[top - 1]] << "\n";

            top--;
        }

        _stack[top++] = i;


        dp[i] = min(dp[i], st.query(j - 1, i - 1));

        // cerr << "update: " << i << " " << dp[i] << "\n";

        st.updateAdd(i, i, dp[i]);

        // cerr << "query interval: " << j - 1 << " " << i - 1 << "\n";
        // cerr << "stack: ";
        // for (int i = 0; i < top; i++) {
        //     cerr << _stack[i] << " ";
        // }
        // cerr << "\n";

        // cerr << "values: ";
        // for (int i = 0; i <= n; i++) {
        //     cerr << st.query(i, i) << " ";
        // }
        // cerr << "\n";
        // cerr << "\n";

    }

    cout << dp[n] << "\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int N = 100 * 1000 + 10;

struct data {
    LL sum;

    int left;
    int right;
    int len;

    bool toSet;
    LL setValue;

    bool toAdd;
    LL addValue;
    LL addTimes;

    data() {}

    data(int _value, int _left, int _right) {
        sum = _value;
        left = _left;
        right = _right;
        len = right - left + 1;

        toSet = false;
        setValue = 0;

        toAdd = false;
        addValue = 0;
        addTimes = 0;
    }

    void lazySet(LL value) {
        toSet = true;
        setValue = value;

        toAdd = false;
        addValue = 0;
        addTimes = 0;
    }

    void lazyAdd(LL value, LL times) {
        toAdd = true;
        addValue += value;
        addTimes += times;
    }

    void update() {
        if (toSet) {
            sum = setValue * len;
            toSet = false;
        }

        if (toAdd) { 
            sum += addValue * len + addTimes * (len - 1) * len / 2LL;
            toAdd = false;
            addValue = 0;
            addTimes = 0;
        }
    }
} tree[4 * N];

int n, q;
LL values[N];

void build(int x, int l, int r) {
    tree[x] = data(0, l, r);
    if (l == r) {
        tree[x].sum = values[l];
    } else {
        int m = (l + r) >> 1;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    }
}

void push(int x, int l, int r) {
    if (l != r) {
        if (tree[x].toSet) {
            tree[2 * x].lazySet(tree[x].setValue);
            tree[2 * x + 1].lazySet(tree[x].setValue);
        }
        if (tree[x].toAdd) {
            tree[2 * x].lazyAdd(tree[x].addValue, tree[x].addTimes);
            tree[2 * x + 1].lazyAdd(tree[x].addValue + tree[2 * x].len * tree[x].addTimes, tree[x].addTimes);
        }
    }
    tree[x].update();
}


void updateSet(int x, int l, int r, int ul, int ur, int v) {
    push(x, l, r);
    if (l > ur || r < ul) {
        return;
    }
    if (ul <= l && r <= ur) {
        tree[x].lazySet(v);
        push(x, l, r);
    } else {
        int m = (l + r) >> 1;
        updateSet(2 * x, l, m, ul, ur, v);
        updateSet(2 * x + 1, m + 1, r, ul, ur, v);
        tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    }
}

void updateAdd(int x, int l, int r, int ul, int ur) {
    push(x, l, r);
    if (r < ul || ur < l) {
        return;
    }
    if (ul <= l && r <= ur) {
        tree[x].lazyAdd(l - ul + 1, 1);
        push(x, l, r);
    } else {
        int m = (l + r) >> 1;
        updateAdd(2 * x, l, m, ul, ur);
        updateAdd(2 * x + 1, m + 1, r, ul, ur);
        tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    }
}

LL query(int x, int l, int r, int ql, int qr) {
    push(x, l, r);
    if (l > qr || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return tree[x].sum;
    }
    int m = (l + r) >> 1;
    return query(2 * x, l, m, ql, qr) + query(2 * x + 1, m + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    build(1, 1, n);

    int op, l, r, v;

    while (q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> v;
            updateSet(1, 1, n, l, r, v);
        } else if (op == 2) {
            updateAdd(1, 1, n, l, r);
        } else {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}

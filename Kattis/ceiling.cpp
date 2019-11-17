// https://icpc.kattis.com/problems/ceiling

#include <bits/stdc++.h>

using namespace std;

struct node {
    int value;
    int left;
    int right;
};

typedef vector <node> tree;

void add(tree &t, int value) {
    if (t.size() == 0) {
        t.push_back((node) {value, -1, -1});
    } else {
        int cur = 0;
        while (true) {
            if (value < t[cur].value) {
                if (t[cur].left == -1) {
                    t[cur].left = t.size();
                    t.push_back((node) {value, -1, -1});
                    break;
                } else {
                    cur = t[cur].left;
                }
            } else {
                if (t[cur].right == -1) {
                    t[cur].right = t.size();
                    t.push_back((node) {value, -1, -1});
                    break;
                } else {
                    cur = t[cur].right;
                }
            }
        }
    }
}

bool dfs(tree &t1, int p1, tree &t2, int p2) {
    if ((t1[p1].left != -1) ^ (t2[p2].left != -1)) {
        return false;
    }
    if ((t1[p1].right != -1) ^ (t2[p2].right != -1)) {
        return false;
    }
    if (t1[p1].left != -1) {
        assert(t2[p2].left != -1);
        if (!dfs(t1, t1[p1].left, t2, t2[p2].left)) {
            return false;
        }
    }
    if (t1[p1].right != -1) {
        assert(t2[p2].right != -1);
        if (!dfs(t1, t1[p1].right, t2, t2[p2].right)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <tree> trees(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int value;
            cin >> value;
            add(trees[i], value);
        }
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (dfs(trees[j], 0, trees[i], 0)) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << "\n";
}


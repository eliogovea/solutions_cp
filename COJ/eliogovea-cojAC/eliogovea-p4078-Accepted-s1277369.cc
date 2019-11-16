#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;
const int INF = 1e9;

int n;
int a[N];
int lg[N];
int st[20][N];


void build() {
    for (int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int query(int l, int r) {
    int x = lg[r - l + 1];
    return max(st[x][l], st[x][r - (1 << x) + 1]);
}


inline int firstPos(int v, int s) {
    int l = s;
    int r = n - 1;

    int p = n;

    while (l <= r) {
        int m = (l + r) >> 1;

        if (query(s, m) >= v) {
            p = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build();

    int q, v, a, b;

    cin >> q;

    while (q--) {
        cin >> v >> a >> b;

        a--;
        b--;

        int p = firstPos(v, a);

        if (p > b) {
            cout << "-1\n";
        } else {
            cout << p + 1 << "\n";
        }
    }
}

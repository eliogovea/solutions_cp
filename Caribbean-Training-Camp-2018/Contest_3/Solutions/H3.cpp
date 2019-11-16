#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;

const int M = 1000 * 1000 * 1000 + 7;

inline void add(int & a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

inline int mul(int a, int b) {
    return (long long)a * b % M;
}

inline int power(int x, int n) {
    int y = 1;
    while (n) {
        if (n & 1) {
            y = mul(y, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector <int> a(n), b(m);
    for (auto & x : a) {
        cin >> x;
    }
    for (auto & x : b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int ans = 1;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] >= b[i]) {
            j++;
        }
        if (j - i < 0) {
            ans = 0;
            break;
        }
        ans = mul(ans, j - i);
    }

    cout << ans << "\n";
    return 0;
}

// KTU Programming Camp (Day 3)
// 100739F

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

LL n, p, q;

int ans[N];

inline LL sum(LL a, LL b) {
    return (a + b) * (b - a + 1) / 2LL;
}

bool solve(LL n, LL p, LL q) {
    if (q > n) {
        return false;
    }
    if (sum(1, q) > p) {
        return false;
    }
    if (sum(n - q + 1, n) < p) {
        return false;
    }
    for (int i = 1; i <= q; i++) {
        ans[i] = i;
    }
    LL need = p - sum(1, q);
    if (need == 0) {
        return true;
    }
    int last = n;
    for (int i = q; i >= 1; i--) {
        if (need <= last - i) {
            ans[i] = i + need;
            return true;
        } else {
            ans[i] = last;
            need -= last - i;
            last--;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;
    LL pp = 0;
    LL qq = 0;
    while (qq <= n) {
        pp += p;
        qq += q;
        if (solve(n, pp, qq)) {
            for (int i = 1; i <= qq; i++) {
                cout << ans[i];
                if (i + 1 <= qq) {
                    cout << " ";
                }
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}
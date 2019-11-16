#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 21) + 10;

int n, m, k, a[100 * 1000 + 10], xa[100 * 1000 + 10];
long long cnt[N];
long long ans[100 * 1000 + 10];

struct query {
    int l, r, id;
};

int BSIZE;

bool operator < (const query &a, const query &b) {
    if (a.l / BSIZE != b.l / BSIZE) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

query q[100 * 1000 + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xa[i] = xa[i - 1] ^ a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].id = i;
    }

    BSIZE = 1 + sqrt((double)n);

    int l = 0;
    int r = 0;
    long long total = 0;
    cnt[0]++;
    sort(q, q + m);

    for (int i = 0; i < m; i++) {
        while (r < q[i].r) {
            total += cnt[xa[r + 1] ^ k];
            cnt[xa[r + 1]]++;
            r++;
        }
        while (r > q[i].r) {
            total -= cnt[xa[r] ^ k] - (long long)(k == 0);
            cnt[xa[r]]--;
            r--;
        }
        while (l < q[i].l) {
            total -= cnt[xa[l] ^ k] - (long long)(k == 0);
            cnt[xa[l]]--;
            l++;
        }
        while (l > q[i].l) {
            total += cnt[xa[l - 1] ^ k];
            cnt[xa[l - 1]]++;
            l--;
        }
        ans[q[i].id] = total;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

}

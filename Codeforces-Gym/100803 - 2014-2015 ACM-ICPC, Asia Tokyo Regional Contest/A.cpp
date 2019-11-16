// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803A

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[20], b[20], c[20];
queue <int> q;
int depth[1 << 16];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        num = 2 * num + a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        depth[i] = -1;
    }
    depth[num] = 0;
    q.push(num);
    while (!q.empty()) {
        int x = q.front(), xx = x;
        vector <int> vx;
        while (x) {
            vx.push_back(x & 1);
            x >>= 1;
        }
        while (vx.size() < n) vx.push_back(0);
        reverse(vx.begin(), vx.end());
        q.pop();
        for (int i = 0; i + 1 < n; i++) {
            if (vx[i] == vx[i + 1]) continue;
            swap(vx[i], vx[i + 1]);
            int y = 0;
            for (int j = 0; j < n; j++) {
                y = 2 * y + vx[j];
            }
            if (depth[y] == -1) {
                depth[y] = depth[xx] + 1;
                q.push(y);
            }
            swap(vx[i], vx[i + 1]);
        }
    }
    int cur = 0;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b[i]; j++) {
            c[sum + j] = cur;
        }
        sum += b[i];
        cur ^= 1;
    }
    int tar1 = 0;
    for (int i = 0; i < n; i++) {
        tar1 = 2 * tar1 + c[i];
    }
    int ans1 = depth[tar1] == -1 ? 1e9 : depth[tar1];
    int tar2 = 0;
    for (int i = 0; i < n; i++) {
        tar2 = 2 * tar2 + (1 - c[i]);
    }
    int ans2 = depth[tar2] == -1 ? 1e9 : depth[tar2];

    cout << min(ans1, ans2) << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int n, q, b, e;
pair <int, int> arr[MAX + 5];
int nxt[MAX + 5];
int dp[MAX + 5];
int val[MAX + 5];

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

   // freopen("dat.txt", "r", stdin);

    while (cin >> n >> q) {
        if (n == 0 && q == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            nxt[i] = n;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            if (arr[i].first == arr[i + 1].first) {
                nxt[arr[i].second] = arr[i + 1].second;
            }
        }
        sort(arr, arr + n, cmp);
        dp[n - 1] = n;
        val[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1];
            val[i] = val[i + 1];
            if (nxt[i] < dp[i]) {
                dp[i] = nxt[i];
                val[i] = arr[i].first;
            }
        }
        while (q--) {
            cin >> b >> e;
            b--;
            e--;
            if (dp[b] > e) {
                cout << "OK\n";
            } else {
                cout << val[b] << "\n";
            }
        }
        cout << "\n";
    }

}

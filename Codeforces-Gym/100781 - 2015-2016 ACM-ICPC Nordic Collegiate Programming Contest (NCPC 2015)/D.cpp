// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781D

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
int t[N];

vector<int> v;

int sum[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        v.push_back(t[i]);
        v.push_back(t[i] + 1000);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
        int s = lower_bound(v.begin(), v.end(), t[i]) - v.begin();
        int e = lower_bound(v.begin(), v.end(), t[i] + 1000) - v.begin();
        sum[s]++;
        sum[e]--;
    }
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        cur += sum[i];
        if (cur > ans) ans = cur;
    }
    ans = (ans + k - 1) / k;
    cout << ans << "\n";
}

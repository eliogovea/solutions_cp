#include <bits/stdc++.h>

using namespace std;

const int MAX = 3005;

string s;
bool ok[MAX][MAX];
int dp[MAX][MAX];
int q, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        ok[i][i] = true;
        dp[i][i] = 1;
        if (i + 1 < n) {
            ok[i][i + 1] = true;
            dp[i][i + 1] = 3;
        }
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            int sum = s[i] - '0' + s[j] - '0';
            int psum = s[i + 1] - '0' + s[j - 1] - '0';
            if (ok[i + 1][j - 1] && sum == psum) {
                ok[i][j] = true;
            }
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            if (ok[i][j]) {
                dp[i][j]++;
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        cout << dp[a][b] << "\n";
    }
    return 0;
}
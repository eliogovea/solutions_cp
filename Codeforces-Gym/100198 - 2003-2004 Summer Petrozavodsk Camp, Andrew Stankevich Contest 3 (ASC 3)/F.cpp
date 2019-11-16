// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 3 (ASC 3)
// 100198F

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n;
string alph;
string a, b;

int d[N][N];
int pos[N];

int dp[N][N];

bool solved[N][N];

char ans1[N][N], ans2[N][N];

bool dx[N][N], dy[N][N];

int men1[N], men2[N];

void solve(int p1, int p2) {
    if ((p1 == 0 && p2 == 0) || solved[p1][p2]) {
        return;
    }
    solved[p1][p2] = true;
    if (p1 == 0) {
            solve(p1, p2 - 1);
            dp[p1][p2] = dp[p1][p2 - 1] + d[men1[pos[b[p2 - 1]]]][pos[b[p2 - 1]]];
            ans1[p1][p2] = alph[men1[pos[b[p2 - 1]]]];
            ans2[p1][p2] = b[p2 - 1];
            dx[p1][p2] = 0;
            dy[p1][p2] = 1;
      return;
    }
    if (p2 == 0) {
            solve(p1 - 1, p2);
            dp[p1][p2] = dp[p1 - 1][p2] + d[pos[a[p1 - 1]]][men2[pos[a[p1 - 1]]]];
            ans1[p1][p2] = a[p1 - 1];
            ans2[p1][p2] = alph[men2[pos[a[p1 - 1]]]];
            dx[p1][p2] = 1;
            dy[p1][p2] = 0;
            return;
    }
    solve(p1 - 1, p2);
    solve(p1, p2 - 1);
    solve(p1 - 1, p2 - 1);
    int x = dp[p1 - 1][p2] + d[pos[a[p1 - 1]]][men2[pos[a[p1 - 1]]]];
    int y = dp[p1][p2 - 1] + d[men1[pos[b[p2 - 1]]]][pos[b[p2 - 1]]];
    int z = dp[p1 - 1][p2 - 1] + d[pos[a[p1 - 1]]][pos[b[p2 - 1]]];
    int mn = min(x, min(y, z));
    if (x == mn) {
        dp[p1][p2] = x;
        ans1[p1][p2] = a[p1 - 1];
        ans2[p1][p2] = alph[men2[pos[a[p1 - 1]]]];
        dx[p1][p2] = 1;
        dy[p1][p2] = 0;
        return;
    }
    if (y == mn) {
        dp[p1][p2] = y;
        ans1[p1][p2] = alph[men1[pos[b[p2 - 1]]]];
        ans2[p1][p2] = b[p2 - 1];
        dx[p1][p2] = 0;
        dy[p1][p2] = 1;
        return;
    }
    if (z == mn) {
        dp[p1][p2] = z;
        ans1[p1][p2] = a[p1 - 1];
        ans2[p1][p2] = b[p2 - 1];
        dx[p1][p2] = 1;
        dy[p1][p2] = 1;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("dissim.in", "r", stdin);
    freopen("dissim.out", "w", stdout);
    cin >> alph >> a >> b;
    n = alph.size();
    for (int i = 0; i < n; i++) {
        pos[alph[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        men1[i] = men2[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (men2[i] == -1 ||d[i][j] < d[i][men2[i]]) {
                men2[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (men1[i] == -1 || d[j][i] < d[men1[i]][i]) {
                men1[i] = j;
            }
        }
    }

    int sa = a.size();
    int sb = b.size();

    solve(sa, sb);

    cout << dp[sa][sb] << "\n";

    string A, B;
    while (sa > 0 || sb > 0) {
        A += ans1[sa][sb];
        B += ans2[sa][sb];
        int nsa = sa - dx[sa][sb];
        int nsb = sb - dy[sa][sb];
        sa = nsa;
        sb = nsb;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    cout << A << "\n";
    cout << B << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k;
int c[N][N];
int ac[N][N];
int f[N][N];
int dp[N][N];
int from[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> c[i][j];
        }
        ac[i][n] = c[i][n];
        for (int j = n - 1; j >= i; j--) {
            ac[i][j] = ac[i][j + 1] + c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i][i] = ac[i][i + 1];
        for (int j = i - 1; j >= 1; j--) {
            f[i][j] = f[i][j + 1] + ac[j][i + 1];
        }
    }
    int ansK = -1;
    int ansL = -1;
    for (int i = 1; i < n; i++) {
        dp[1][i] = f[i][1];
        from[1][i] = -1;
        // cerr << i << " " << dp[1][i] << "\n";
    }
    for (int i = 2; i <= k; i++) {
        for (int l = i; l < n; l++) {
            for (int ll = 1; ll < l; ll++) {
                if (dp[i - 1][ll] + f[l][ll + 1] >= dp[i][l]) {
                    dp[i][l] = dp[i - 1][ll] + f[l][ll + 1];
                    from[i][l] = ll;
                }
            }
        }
    }

    int t = 0;
    for (int l = 1; l < n; l++) {
        if (dp[k][l] >= t) {
            t = dp[k][l];
            ansL = l;
        }
    }

    cout << dp[k][ansL] << "\n";
    vector <int> p;
    for (int i = k; i >= 1; i--) {
        p.push_back(ansL);
        ansL = from[i][ansL];
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < k; i++) {
        cout << p[i];
        if (i + 1 < k) {
            cout << " ";
        }
    }
    cout << "\n";
}

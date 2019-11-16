#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> v(n);
    for (auto & x : v) {
        cin >> x;
        x %= m;
    }

    vector <vector <bool> > dp(n, vector <bool> (m, false));

    dp[0][v[0]] = true;

    for (int i = 0; i + 1 < n; i++) {
        for (int r = 0; r < m; r++) {
            if (dp[i][r]) {
                dp[i + 1][ (r + v[i + 1]) % m ] = true;
                dp[i + 1][ (r + m - v[i + 1]) % m ] = true;
            }
        }
    }

    cout << (dp[n - 1][0] ? "valid" : "invalid") << "\n";
}


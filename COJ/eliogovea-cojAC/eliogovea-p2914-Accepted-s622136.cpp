#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110, MAXM = 10010;

int n, m, t[MAXN];
double p[MAXN], dp[MAXN][2 * MAXM], aux, sol;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 0; i < n; i++) scanf("%lf", &p[i]), p[i] /= 100.0;
    dp[0][0] = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
            dp[i + 1][j + t[i]] += dp[i][j] * p[i];
        }

    for (int i = 1; i <= n; i++) {
        aux = 0.0;
        for (int j = m; j < m + t[i - 1]; j++)
            aux += dp[i][j];
        sol += (double(i)) * aux;
    }

    aux = 0.0;
    for (int i = 0; i < m; i++)
        aux += dp[n][i];
    sol += (double(n)) * aux;

    cout.precision(0);
    cout << fixed << sol << endl;
}

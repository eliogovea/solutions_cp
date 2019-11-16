// 2017-2018 ACM-ICPC Southeastern European Regional Programming Contest (SEERC 2017)
// 101669A

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> k >> n;

    const int A = 26;
    vector <int> h(A);
    for (auto & x : h) {
        cin >> x;
    }

    string a, b;
    cin >> a >> b;

    const int M = 1000 * 1000 * 1000 + 7;

    vector <vector <int> > f(n + 1, vector <int> (k + 1));

    f[0][0] = 1;
    for (int j = 0; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            f[i + 1][j] += f[i][j];
            if (f[i + 1][j] >= M) {
                f[i + 1][j] -= M;
            }
            if (j < k && a[j] == b[i]) {
		   int ii = i + 1 + h[a[j] - 'A'];
		   if (ii > n) {
		   	ii = n;
		   }
		   f[ii][j + 1] += f[i][j];
		   if (f[ii][j + 1] >= M) {
		   	f[ii][j + 1] -= M;
		   }
            }
        }
    }

    cout << f[n][k] << "\n";
}

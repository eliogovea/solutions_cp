// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147D

#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
long long c[N + 5][N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("popcorn.in", "r", stdin);
	for (int i = 0; i <= N; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << c[n][m] << "\n";
	}
}

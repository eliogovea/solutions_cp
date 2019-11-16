#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

const int N = 1000;

int C[N + 5][N + 5];
int sum[N + 5][N + 5];


int t;
int n;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= N; i++) {
		C[i][0] = C[i][i] = 1;
		sum[i][0] = C[i][0];
		for (int j = 1; j < i; j++) {
			add(C[i][j], C[i - 1][j - 1]);
			add(C[i][j], C[i - 1][j]);
			add(sum[i][j], sum[i][j - 1]);
			add(sum[i][j], C[i][j]);
		}
		if (i >= 1) {
			add(sum[i][i], sum[i][i - 1]);
			add(sum[i][i], C[i][i]);
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
            int x = sum[b[i]][min(b[i], a[i] - 1)];
            add(x, MOD - sum[b[i]][0]);
			ans = mul(ans, x);
		}
		cout << ans << "\n";
	}
}

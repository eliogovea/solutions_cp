#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int y = 1;
	while (n) {
		if (n & 1) {
			y = mul(y, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return y;
}

const int N = 5 * 1000;
const int C = 100;
int comb[C][C];
int nd[N + 2];
int fact[N + 4], invFact[N + 2];
int edges[N + 2][N + 2], ways[N + 2][N + 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			nd[j]++;
		}
	}
	for (int i = 0; i < C; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1];
			add(comb[i][j], comb[i - 1][j]);
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int n = 1; n <= N; n++) {
			edges[n][k] = edges[n - 1][k];
			add(edges[n][k], min(nd[n], k));
			if (n == 1) {
				ways[n][k] = 1;
			} else {
				ways[n][k] = ways[n - 1][k];
				ways[n][k] = mul(ways[n][k], comb[nd[n]][min(nd[n], k)]);
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << edges[n][k] << " " << ways[n][k] << "\n";
	}
}

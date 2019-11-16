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

string s;
int n;
int dp[15][55][15];
int C[105][105];
int freq[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		freq[s[i] - '0']++;
	}
	for (int i = 0; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1];
			add(C[i][j], C[i - 1][j]);
		}
	}

	int I = n / 2;
	int P = n - I;
	/// 0
	if (n & 1) {
		for (int p = 0; p < P && p <= freq[0]; p++) {
			int i = freq[0] - p;
			if (i < 0 || i > I) {
				continue;
			}
			dp[0][p][0] = mul(C[P - 1][p], C[I][i]);
		}
	} else {
		for (int p = 0; p <= P && p <= freq[0]; p++) {
			int i = freq[0] - p;
			if (i < 0 || i >= I) {
				continue;
			}
			dp[0][p][0] = mul(C[P][p], C[I - 1][i]);
		}
	}
	int total = freq[0];
	for (int d = 1; d <= 9; d++) {
		for (int p = 0; p <= P && p <= total; p++) {
			int i = total - p;
			if (i < 0 || i > I) {
				continue;
			}
			for (int r = 0; r < 11; r++) {
				if (dp[d - 1][p][r] != 0) {
					for (int pp = 0; p + pp <= P && pp <= freq[d]; pp++) {
						int ii = freq[d] - pp;
						if (ii < 0 || i + ii > I) {
							continue;
						}
						int diff = pp - ii;
						int nr = (r + ((d * (pp - ii)) % 11) + 11) % 11;
						add(dp[d][p + pp][nr], mul(dp[d - 1][p][r], mul(C[I - i][ii], C[P - p][pp])));
					}
				}
			}
		}
		total += freq[d];
	}
	cout << dp[9][P][0] << "\n";
}

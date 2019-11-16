#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

const int N = 10000000;

int sum[N + 5];
int C[1600][1600];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= N; i++) {
		sum[i] = 1;
	}
	for (int i = 2; i * i <= N; i++) {
		if (sum[i] == 1) {
			for (int j = i * i; j <= N; j += i) {
				sum[j] = 0;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (sum[i] == 1) {
			int x = i;
			int rx = 0;
			while (x) {
				rx = 10 * rx + (x % 10);
				x /= 10;
			}
			if (rx != i) {
				sum[i] = 0;
			}
		}
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < 1600; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (sum[b] - sum[a - 1] - c + 1 < 0 || sum[b] - sum[a - 1] - c + 1 < c) {
			cout << "0\n";
		} else {
			cout << C[sum[b] - sum[a - 1] - c + 1][c] << "\n";
		}
	}
}

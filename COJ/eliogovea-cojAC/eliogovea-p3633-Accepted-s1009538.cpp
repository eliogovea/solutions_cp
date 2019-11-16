#include <bits/stdc++.h>

using namespace std;

long long n;
int k;
int pos[25];

int rem[70];

long long dp[25][25][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	rem[0] = 1;
	for (int i = 1; i <= 65; i++) {
		rem[i] = (rem[i - 1] * 2) % 7;
	}
	while (cin >> n) {
		cin >> k;
		int ones = 0;
		for (int i = 0; i < k; i++) {
            cin >> pos[i];
			if (n & (1LL << pos[i])) {
				ones++;
				n ^= (1LL << pos[i]);
			}
		}
		for (int l = 0; l <= k; l++) {
			for (int o = 0; o <= ones; o++) {
				for (int r = 0; r < 7; r++) {
					dp[l][o][r] = -1LL;
				}
			}
		}
		dp[0][0][n % 7LL] = n;
		for (int l = 0; l < k; l++) {
			for (int o = 0; o <= ones && o <= l; o++) {
				for (int r = 0; r < 7; r++) {
					if (dp[l][o][r] != -1LL) {
						///zero
						dp[l + 1][o][r] = max(dp[l + 1][o][r], dp[l][o][r]);
						if (o < ones) {
							int nr = (r + rem[pos[l]]) % 7;
							long long tmp = dp[l][o][r] + (1LL << pos[l]);
							dp[l + 1][o + 1][nr] = max(dp[l + 1][o + 1][nr], tmp);
						}
					}
 				}
			}
		}
		cout << dp[k][ones][0] << "\n";
	}
}

// 2014 ACM-ICPC Vietnam National Second Round
// 100541D

#include <bits/stdc++.h>

using namespace std;

int next[105][55];
long long toadd[105][55];

int t;
long long n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 100; i++) {
		next[i][0] = (2 * i) % 100;
		toadd[i][0] = (2 * i >= 100);
	}
	for (int i = 1; i <= 31; i++) {
		for (int j = 0; j <= 100; j++) {
			next[j][i] = next[next[j][i - 1]][i - 1];
			toadd[j][i] = toadd[j][i - 1] + toadd[next[j][i - 1]][i - 1];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int cur = n % 100;
		long long ans = n - cur;
		for (int i = 31; i >= 0; i--) {
			if (k & (1LL << i)) {
				ans += 100LL * toadd[cur][i];
				cur = next[cur][i];
			}
		}
		ans += (long long)cur;
		cout << ans << "\n";
	}
}

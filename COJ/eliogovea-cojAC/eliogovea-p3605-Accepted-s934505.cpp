#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int L = 5005;

int n;
string p[N + 5];
string t;

int pi[L];

bool match[N + 5][L];

bool dp[(1 << N) + 5][L];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		p[i] += '$';
		for (int j = 1, k = 0; j < p[i].size(); j++) {
			while (k > 0 && p[i][j] != p[i][k]) {
				k = pi[k - 1];
			}
			if (p[i][j] == p[i][k]) {
				k++;
			}
			pi[j] = k;
		}
		for (int j = 0, k = 0; j < t.size(); j++) {
			while (k > 0 && t[j] != p[i][k]) {
				k = pi[k - 1];
			}
			if (t[j] == p[i][k]) {
				k++;
			}
			if (k == p[i].size() - 1) {
				match[i][j + 1] = true;
			}
		}
	}
	int ans = 0;
	dp[0][0] = true;
	for (int i = 1; i <= t.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (match[j][i]) {
				for (int mask = 0; mask < (1 << n); mask++) {
					if (mask & (1 << j)) {
						dp[mask][i] |= dp[mask ^ (1 << j)][i - p[j].size() + 1];
					}
				}
			}
		}
		dp[0][i] = 1;
		if (dp[(1 << n) - 1][i]) {
            ans++;
		}
	}
	cout << ans << "\n";
}

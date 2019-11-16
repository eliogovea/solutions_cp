#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int n, k;
ll dp[1 << 18][18], a[18], sol;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[1 << i][i] = 1;
	}
	for (int mask = 1; mask < (1 << n); mask++)
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				for (int j = 0; j < n; j++)
					if (!(mask & (1 << j)) && abs(a[j] - a[i]) > k)
						dp[mask | (1 << j)][j] += dp[mask][i];
	for (int i = 0; i < n; i++)
		sol += dp[(1 << n) - 1][i];
	cout << sol << "\n";
}

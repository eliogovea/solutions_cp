#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int n, k;
ll dp[1 << 17][17], a[17], sol;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
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
	printf("%lld\n", sol);
}

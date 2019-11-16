#include <cstdio>

typedef long long ll;

int tc, x, y, sol;
ll dp[100][20], ac[100];

const int MAXN = 64;

int main() {
	for (int i = 0; i <= 9; i++) dp[1][i] = 1ll;
	for (int i = 1; i <= MAXN; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = j; k <= 9; k++)
				dp[i + 1][k] += dp[i][j];
	for (int i = 1; i <= MAXN; i++)
		for (int j = 0; j <= 9; j++)
			ac[i] += dp[i][j];
	scanf("%d", &tc);
	while (tc--) {
		ll a, b, sol = 0;
		scanf("%lld%lld", &a, &b);
		printf("%lld %lld\n", a, ac[b]);
	}
}

#include <cstdio>

int n, dp[1000];

int main() {
	scanf("%d", &n);
	int sum = n * (n + 1) / 2;
	if (sum & 1) printf("0\n");
	else {
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = sum; j >= i; j--)
				dp[j] += dp[j -i];
		printf("%d\n", dp[sum / 2] / 2);
	}
}

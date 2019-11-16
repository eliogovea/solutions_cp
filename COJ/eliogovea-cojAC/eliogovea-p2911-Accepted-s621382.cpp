#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 10010, mod = 1e9 + 7;

int n, m, a[MAXN], dp[MAXN], sum[MAXN], sol;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + a[i];
	if (sum[0] <= m) {
		printf("1\n");
		return 0;
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (sum[i + 1] <= m)
			for (int j = 0; j <= m; j++)
				if (sum[i + 1] + j <= m && sum[i + 1] + j + a[i] > m)
					sol = (sol + dp[j]) % mod;
		for (int j = m; j >= a[i]; j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	}
	printf("%d\n", sol);
}

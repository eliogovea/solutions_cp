#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXT = 25010;

int n, q, a, b, c, dp[MAXT];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (b == 0) {
			for (int i = c; i < MAXT; i++)
				dp[i] = max(dp[i], dp[i - c] + a);
		}
		else {
			int k = 0;
			while (a - k * k * b > 0) {
				for (int i = MAXT - 1; i >= c; i--)
					dp[i] = max(dp[i], dp[i - c] + a - k * k * b);
            k++;
			}
		}
	}
	for (scanf("%d", &q); q--;) {
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}
}

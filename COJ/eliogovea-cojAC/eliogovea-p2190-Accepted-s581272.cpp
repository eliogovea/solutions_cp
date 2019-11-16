#include <cstdio>
using namespace std;

const int MAXN = 33;
typedef long long ll;

int c, n;
ll dp[MAXN + 10];

int main()
{
	dp[0] = dp[1] = 1ll;
	for (int i = 2; i <= MAXN; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - 1 - j];
	for (scanf("%d", &c); c--;)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n/2]);
	}
}

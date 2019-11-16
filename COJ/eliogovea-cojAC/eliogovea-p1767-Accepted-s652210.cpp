#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, r, c, ra, f;
long long a[1005][1005];

int main() {
  //freopen("e.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &a[i][j]);
			a[i][j] += a[i][j - 1];
		}
	scanf("%d", &f);
	while (f--) {
		scanf("%d%d%d", &r, &c, &ra);
		r++; c++;
		long long sol = 0;
		for (int i = r, j = ra; i && j >= 0; i--, j--)
			sol += a[i][min(m, c + j)] - a[i][max(0, c - j - 1)];
		for (int i = r + 1, j = ra - 1; i <= n && j >= 0; i++, j--)
			sol += a[i][min(m, c + j)] - a[i][max(0, c - j - 1)];
		printf("%lld\n", sol);
	}
}

#include <cstdio>

int tc, n, k, a[50005], sol, lo, hi, mid, ff, mn;

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &k);
		mn = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sol = 0;
		int lo = 0, hi = 1e9, mid, fmid;
		while (lo + 1 < hi) {
			mid = (lo + hi + 1) >> 1;
			ff = 0;
			for (int i = 0; i < n; i++) ff += a[i] / mid;
			if (ff >= k) sol = lo = mid;
			else hi = mid;
		}
		printf("%d\n", sol);
	}
}

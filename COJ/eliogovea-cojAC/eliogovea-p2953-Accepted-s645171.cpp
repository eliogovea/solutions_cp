#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

int n, q, a[1000006], x, sol;

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	while (scanf("%d%d", &n, &q) == 2) {
		for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (i >= 3) a[i] += a[i - 1];
		}
		while (q--) {
			scanf("%d", &x);
			printf("%d", lower_bound(a + 2, a + n + 1, x) - a - 1);
			if (q) printf(" ");
			else printf("\n");
		}
	}
}

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int n, mx, id;
pair<int, int> a[MAXN];

int main() {
  //freopen("e.in", "r", stdin);
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
		sort(a, a + n);
		mx = -1;
		for (int i = 0, p; i < n; i++) {
			p = lower_bound(a + i, a + n, make_pair(a[i].first + a[i].second, -100)) - a - i - 1;
			if (p > mx) {
				mx = p;
				id = i;
			}
		}
		printf("%d %d\n", a[id].first, mx);
	}
}

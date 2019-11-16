#include <cstdio>

using namespace std;

int c[4], a[105], be, en, ans;

int main() {
  scanf("%d%d%d", c + 1, c + 2, c + 3);
	c[2] *= 2; c[3] *= 3;
	scanf("%d%d", &be, &en); a[be]++; a[en]--;
	scanf("%d%d", &be, &en); a[be]++; a[en]--;
	scanf("%d%d", &be, &en); a[be]++; a[en]--;
	for (int i = 1; i <= 100; i++) {
		a[i] += a[i - 1];
		ans += c[a[i]];
	}
	printf("%d\n", ans);
}

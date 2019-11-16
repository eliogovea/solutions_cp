// KTU Programming Camp (Day 5)
// 100741D

#include <cstdio>

int n, x;

int main() {
	scanf("%d", &n);
	int ans = 0;
	while (n--) {
		scanf("%d", &x);
		ans ^= x;
	}
	printf("%d\n", ans);
}
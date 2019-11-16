#include <cstdio>

const int MAXN = 1000010;

int n, q, x, ind, nota[MAXN];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < x; j++) nota[ind + j] = i;
		ind += x;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d", &x);
		printf("%d\n", nota[x]);
	}
}

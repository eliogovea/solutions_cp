#include <cstdio>

const int MAXN = 30;

int n, a[MAXN + 5], b[MAXN + 5];

int main() {
	b[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= MAXN; i++) {
		a[i] = a[i - 2] + b[i - 1];
		b[i] = b[i - 2] + 2 * a[i - 1];
	}
	while (scanf("%d", &n) && n != -1) printf("%d\n", b[n]);
}

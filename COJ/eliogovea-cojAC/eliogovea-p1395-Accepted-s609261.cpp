#include <cstdio>
#include <cmath>

const int MAXN = 10000000;

int tc, n, cant[MAXN + 10];

int main() {
	double tot = 0.0;
	cant[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		tot += log10(i);
		cant[i] = (int)tot + 1;
	}
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		printf("%d\n", cant[n]);
	}
}

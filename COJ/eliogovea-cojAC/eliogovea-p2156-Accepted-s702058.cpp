#include <cstdio>

int tc, n;
double x, p[105];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%lf", &n, &x);
		p[1] = 1.0;
		for (int i = 1; i < n; i++)
			p[i + 1] = p[i] * (1.0 - x) + (1.0 - p[i]) * x;
		printf("%.5lf\n", x * p[n] + (1.0 - x) * (1.0 - p[n]));
	}
}

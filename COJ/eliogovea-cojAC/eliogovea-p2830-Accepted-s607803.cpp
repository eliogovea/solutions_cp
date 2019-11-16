#include <cstdio>

double n, m;

int main() {
	while (scanf("%lf%lf", &n, &m) == 2)
		printf("%.2lf\n", n * (m + 1) * (m + 1) / (2 * (m + 1)));
}

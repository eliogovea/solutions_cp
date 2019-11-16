#include <cstdio>
#include <cmath>

int tc;
double l, xa, xb, ya, yb;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lf%lf%lf%lf%lf", &l, &xa, &ya, &xb, &yb);
		ya -= l;
		printf("%.3lf\n", l + sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)));
	}
}

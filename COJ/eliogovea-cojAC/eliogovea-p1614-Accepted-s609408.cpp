#include <cstdio>
#include <cmath>

double a, b, s, n, m, ang, vel;

int main() {
	while (scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n)) {
		if (a == 0.0 && b == 0.0 && s == 0.0 && m == 0.0 && n == 0.0)
            break;
		if (m == 0.0) {
			vel = n * b / s;
			printf("90.00 %.2lf\n", vel);
		}
		else if (n == 0.0) {
			vel = m * a / s;
			printf("0.00 %.2lf\n", vel);
		}
		else {
			ang = atan((n * b) / (m * a));
			vel = m * a / cos(ang) / s;
			printf("%.2lf %.2lf\n", ang * 180.0 / M_PI, vel);
		}
	}
}

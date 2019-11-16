#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-9;

int n;
double X0, Y0, Dx, Dy, V, Vx, Vy, sol;

int main() {
	while (scanf("%d", &n) && n) {
    scanf("%lf%lf%lf%lf%lf", &X0, &Y0, &Dx, &Dy, &V);
		sol = 1e10;
		Vx = Dx * V;
		Vy = Dy * V;
		double x, y, v;
		for (int i = 0; i < n; i++) {
		  scanf("%lf%lf%lf", &x, &y, &v);
			if (fabs(x - X0) <= eps && fabs(y - Y0) <= eps)
				sol = 0.0;
			else if (fabs(Vx * Vx + Vy * Vy - v * v) <= eps) {
				double t = -((Y0 - y) * (Y0 - y) + (X0 - x) * (X0 - x))
										/ (2.0 * (Vx * (X0 - x) + Vy * (Y0 - y)));
				if (t + eps >= 0.0) sol = min(sol, t);
			}
			else {
				double d = 4.0 * (Vx * (X0 - x) + Vy * (Y0 - y)) * (Vx * (X0 - x) + Vy * (Y0 - y))
									- 4.0 * (Vx * Vx + Vy * Vy - v * v) * ((Y0 - y) * (Y0 - y) + (X0 - x) * (X0 - x));
				if (d + eps >= 0.0) {
					double b = 2.0 * (Vx * (X0 - x) + Vy * (Y0 - y));
					double a = Vx * Vx + Vy * Vy - v * v;
					double t1 = (-b - sqrt(d)) / (2.0 * a);
					if (t1 + eps >= 0.0) sol = min(sol, t1);
					double t2 = (-b + sqrt(d)) / (2.0 * a);
					if (t2 + eps >= 0.0) sol = min(sol, t2);
				}
			}
		}
    if (sol == 1e10) printf("No solution\n");
    else printf("%.2lf\n", sol);
	}
}

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const double eps = 1e-7;

int n;
double a[MAXN], s;

double f(double x) {
    double ret = 0.0;
    for (int i = 0; i < n; i++) ret += 1000.0 / (a[i] - x);
    return ret + 1e-9;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
        if (n == 1) printf("The planet is doomed.\n");
        else {
            sort(a, a + n);
            printf("%d", n - 1);
            for (int i = 1; i < n; i++) {
                double p1 = a[i - 1], p2 = a[i];
                while (true) {
                    double m = (p1 + p2) / 2.0, fm = f(m);
                    if (fabs(fm) < eps) {
                        s = m + 1e-9;
                        break;
                    }
                    if (fm > eps) p2 = m;
                    else p1 = m;
                }
                printf(" %.3lf", s);
            }
            printf("\n");
        }
    }
}

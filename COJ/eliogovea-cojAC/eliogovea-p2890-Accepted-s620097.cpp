#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100005;
const double eps = 1e-5;

int n;
double x[MAXN], v[MAXN], sol;

double f(double t) {
    double mx = -1e10;
    double mn = 1e10;
    for (int i = 0; i < n; i++)
        mx = max(mx, x[i] + t * v[i]),
        mn = min(mn, x[i] + t * v[i]);
    return mx - mn;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++)
        	scanf("%lf%lf", &x[i], &v[i]);
        double lo = 0.0, hi = 1e10;
        int iter = 0;
        while (iter < 350) {
            double t1 = lo + (hi - lo) / 3.0, t2 = hi - (hi - lo) / 3.0;
            double x1 = f(t1), x2 = f(t2);
            if (x1 > x2) lo = t1, sol = x2;
            else hi = t2,sol = x1;
            iter++;
        }
        printf("%.2lf\n", sol);
    }
}

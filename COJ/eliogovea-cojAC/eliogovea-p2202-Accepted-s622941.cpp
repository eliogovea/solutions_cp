#include <cstdio>
#include <algorithm>

using namespace std;

long long  xa, ya, za, xb, yb, zb, dx, dy, dz, g;

int main() {
    while (scanf("%lld%lld%lld%lld%lld%lld", &xa, &ya, &za, &xb, &yb, &zb) == 6) {
        dx = abs(xa - xb);
        dy = abs(ya - yb);
        dz = abs(za - zb);
       printf("%lld\n", 1ll + __gcd(dx, __gcd(dy, dz)));
    }
}

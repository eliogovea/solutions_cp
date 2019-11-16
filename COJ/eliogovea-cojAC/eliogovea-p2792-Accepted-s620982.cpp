#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 40010;

typedef long long ll;

ll n, r;
int ang[MAXN], cas;
ll sol;

int main() {
    //freopen("e.in", "r", stdin);
    while (scanf("%lld%lld", &n, &r) && n | r) {
        sol = n * (n - 1ll) * (n - 2ll) / 6ll;
        for (int i = 0, a, b; i < n; i++) {
            scanf("%d.%d", &a, &b);
            ang[i] = 1000 * a + b;
            ang[n + i] = ang[i] + 360000;
        }
        sort(ang, ang + 2 * n);
        for (int p1 = 0, p2 = 0; p1 < n; p1++) {
            while (ang[p1] + 180000 >= ang[p2]) p2++;
            p2--;
            ll x = ll(p2 - p1);
            sol -= x * (x - 1ll) / 2ll;
        }
        printf("Case %d: %lld\n", ++cas, sol);
    }
}

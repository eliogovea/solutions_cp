#include <cstdio>
using namespace std;

long long tc, n, m;

int main()
{
    scanf("%lld", &tc);
    while (tc--) {
        scanf("%lld%lld", &n, &m);
        if (m % n) printf("-1\n");
        else printf("%lld %lld\n", n, m);
    }
    return 0;
}

/// GCD

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], sol;

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= 100; i++) {
            int g = a[0];
            for (int j = 0; j < n; j++) {
                g = __gcd(g, a[j]);
                if (g % i) g = a[j];
                if (g == i) {sol++; break;}
            }
        }
        printf("%d\n", sol);
        sol = 0;
    }
}

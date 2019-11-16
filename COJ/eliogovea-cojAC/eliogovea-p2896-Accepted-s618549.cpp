#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int n, a[MAXN + 10], sol[MAXN + 10], q, v;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= MAXN; i++) {
        int g = 0, c = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) {
                if (g == 0) g = a[j];
                else g = __gcd(g, a[j]);
                c++;
                if (g == i)sol[i] = max(sol[i], c);
            }
        }
    }

    for (int i = MAXN, x = sol[MAXN]; i; i--) {
            if (sol[i]) x = sol[i];
            else sol[i] = x;
        }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &v);
        printf("%d\n", sol[v]);
    }
}

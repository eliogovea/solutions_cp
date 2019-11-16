#include <cstdio>
#include <algorithm>
using namespace std;

int n, esta[30], a[1000000][30], uno, sol;
int gcd[30][30];

int main() {

    for (int i = 1; i <= 25; i++)
        for (int j = 1; j <= 25; j++) gcd[i][j] = __gcd(i, j);

    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        if (x != 1)esta[x] = 1;
        else uno++;
    }
    int last = 0;
    for (int i = 1; i <= 25; i++)
        if (esta[i]) {
            for (int j = 0; j < last; j++) {
                bool b = true;
                for (int k = 1; k <= a[j][0]; k++)
                    if (gcd[ i ][ a[j][k] ] != 1) {
                        b = false;
                        break;
                    }
                if (b) {
                    for (int k = 1; k <= a[j][0]; k++)
                        a[last][k] = a[j][k];
                    a[last][ a[last][0] = a[j][0] + 1 ] = i;
                    last++;
                }
            }
            a[last][0] = 1;
            a[last][1] = i;
            last++;
        }
    for (int i = 0; i < last; i++)
        sol = max(sol, a[i][0]);
    printf("%d\n", sol + uno);
}

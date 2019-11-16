#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAXN = 35;

ll c[MAXN][MAXN];

ll cmb(int a, int b) {
    if (b > a - b) b = a - b;
    if (b == 0) return 1ll;
    if (c[a][b]) return c[a][b];
    else return c[a][b] = cmb(a - 1, b - 1) + cmb(a - 1, b);
}

int n;

int main() {
    cin >> n;
    if (n <= 7) {
        cout << "1.0000000\n";
        return 0;
    }
    double a, b;
    a = pow(2, n);
    for (int i = 0; i <= 3; i++)
        b += ((double)cmb(n, i)) / a + (double)cmb(n, n - i) / a;
    cout.precision(7);
    cout << fixed << b << endl;
}

#include <iostream>
using namespace std;

const int MAXN = 1000005;

int n, sol;
bool mark[MAXN];

int main() {
    while (cin >> n) {
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0) {
                if (mark[i]) sol = max(sol, i);
                else mark[i] = 1;
                if (i * i == n) break;
                if (mark[n / i]) sol = max(sol, n / i);
                else mark[n / i] = 1;
            }
    }
    cout << sol << endl;
}

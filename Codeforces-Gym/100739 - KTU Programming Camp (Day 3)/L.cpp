// KTU Programming Camp (Day 3)
// 100739L

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

LL power(LL x, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1LL) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1LL;
    }
    return res;
}

LL a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    cout << power(2, a) << "\n";
}

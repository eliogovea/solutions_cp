#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;

inline int mul(int a, int b) {
    return (long long)a * b % M;
}

inline int power(int x, int n) {
    int y = 1;
    while (n) {
        if (n & 1) {
            y = mul(y, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    n %= M;

    int ans = n;
    ans = mul(ans, n + 1);
    ans = mul(ans, n + 1);
    ans = mul(ans, n + 2);
    ans = mul(ans, power(12, M - 2));

    cout << ans << "\n";
}

#include <iostream>

using namespace std;

inline long long solve(long long n) {
    if (n == 1) {
        return 1;
    }
    long long ans = 1;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long pk = 1;
            long long k = 0;
            while (n % i == 0) {
                pk *= i;
                k++;
                n /= i;
            }
            long long v = (k + 1LL) * pk - k * (pk / i);

            ans *= v;
        }
    }

    if (n > 1) {
        long long v = 2 * n - 1;
        ans *= v;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
}

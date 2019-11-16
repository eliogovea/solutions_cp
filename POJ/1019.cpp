#include <iostream>
#include <cassert>

using namespace std;

int digits(int n) {
    if (n == 0) {
        return 1;
    }
    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

long long L(long long n) {
    int d = digits(n);
    long long p = 1;
    long long res = 0;

    for (int l = 1; l < d; l++) {
        long long low = p;
        long long high = 10LL * p - 1LL;

        long long from = n + 1 - high;
        long long to = n + 1 - low;

        long long sum = (from + to) * (to - from + 1LL) / 2LL;
        
        res += sum * (long long)l;
        p *= 10LL;
    }

    long long low = p;
    long long high = n;

    long long from = n + 1 - high;
    long long to = n + 1 - low;

    long long sum = (from + to) * (to - from + 1LL) / 2LL;

    res += sum * (long long)d;

    return res;
}

long long l(long long n) {
    int t = digits(n);
    long long p = 1;
    long long res = 0;
    for (int d = 1; d < t; d++) {
        long long low = p;
        long long high = 10LL * p - 1LL;

        res += (high - low + 1LL) * (long long)d;

        p *= 10LL;
    }

    long long low = p;
    long long high = n;

    res += (high - low + 1LL) * (long long)t;

    return res;
}

long long d(int n, int p) {
    int t = digits(n);
    assert(1 <= p && p <= t); 

    p = t + 1 - p;

    int res = -1;
    for (int i = 0; i < p; i++) {
        res = n % 10LL;
        n /= 10LL;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        long long answer = -1;

        {
            long long low = 1;
            long long high = 1;
            while (L(high) < n) {
                high *= 2LL;
            }

            long long pos = low;
            while (low <= high) {
                long long middle = (low + high) / 2LL;
                if (L(middle) < n) {
                    pos = middle;
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            }

            n -= L(pos);
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        {
            long long low = 1;
            long long high = 1;
            while (l(high) < n) {
                high *= 2LL;
            }

            long long pos = low;
            while (low <= high) {
                long long middle = (low + high) / 2LL;
                if (l(middle) < n) {
                    pos = middle;
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            }

            n -= l(pos);

            answer = d(pos + 1, n);
        }

        cout << answer << "\n";
    }
}

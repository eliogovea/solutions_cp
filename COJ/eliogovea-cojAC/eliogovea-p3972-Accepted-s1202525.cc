#include <bits/stdc++.h>

using namespace std;

int getGrundy(long long x) {
        long long p12 = 1;
        while (p12 <= x / 12LL) {
                p12 *= 12LL;
        }
        x -= p12;
        if (x < p12) {
                return 1;
        }
        if (x < 3LL * p12) {
                return 2;
        }
        if (x < 5LL * p12) {
                return 3;
        }
        return 0;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);


        int t;
        cin >> t;

        while (t--) {
                int n;
                cin >> n;
                int xorSum = 0;
                while (n--) {
                        long long x;
                        cin >> x;
                        xorSum ^= getGrundy(x);
                }

                cout << (xorSum == 0 ? "Derek" : "Henry") << "\n";
        }
}


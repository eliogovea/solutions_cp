#include <bits/stdc++.h>

using namespace std;

const unsigned long long N = 1000 * 1000 + 10;

unsigned long long sieve[N];
unsigned long long primes[N];
unsigned long long cp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mn = 0;
    int mx = 0;

    vector <int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    sort(vals.begin(), vals.end());

    if (vals.back() > 100) {
        cout << "No\n";
        return 0;
    }

    if (vals.back() == 100) {
        if (n == 1) {
            cout << "Yes\n";
        } else {
            if (vals[n - 2] == 0) {
                cout << "Yes\n";
            } else if (n == 2 && vals[0] == 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        return 0;
    }

    for (auto x : vals) {

        if (x == 0) {
            mn += 0;
            mx += 1;
        } else {
            mn += 2 * x - 1;
            mx += 2 * x + 1;
        }
    }

    if (mn <= 200 && 200 < mx) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

/*
    //freopen("dat.txt","r",stdin);

    for (unsigned long long i = 2; i * i < N; i++) {
        if (!sieve[i]) {
            for (unsigned long long j = i * i; j < N; j += i) {
                if (!sieve[j]) {
                    sieve[j] = i;
                }
            }
        }
    }

    cp = 0;

    for (unsigned long long i = 2; i < N; i++) {
        if (!sieve[i]) {
            sieve[i] = i;
            primes[cp++] = i;
        }
    }

    unsigned long long t;
    cin >> t;

    while (t--) {
        unsigned long long n;
        cin >> n;

        unsigned long long nn = n;

        unsigned long long ans = 0;

        if (n < N) {
            while (n > 1) {
                unsigned long long p = sieve[n];
                unsigned long long e = 0;
                while (n > 1 && sieve[n] == p) {
                    e++;
                    n /= p;
                }
                ans += (nn / p) * e;
            }
        } else {
            for (unsigned long long i = 0; i < cp && primes[i] * primes[i] <= n; i++) {
                if (n % primes[i] == 0) {
                    unsigned long long e = 0;
                    while (n % primes[i]) {
                        e++;
                        n /= i;
                    }
                    ans += (nn / i) * e;
                }
            }
            if (n > 1) {
                ans += (nn / n);
            }
        }

        cout << ans << "\n";
    }
*/

}

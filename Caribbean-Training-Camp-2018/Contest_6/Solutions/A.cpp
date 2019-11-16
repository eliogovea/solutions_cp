#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 10;

int sieve[N];
int primes[N];
int cp;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    for (int i = 2; i * i < N; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j < N; j += i) {
                if (!sieve[j]) {
                    sieve[j] = i;
                }
            }
        }
    }

    cp = 0;

    for (int i = 2; i < N; i++) {
        if (!sieve[i]) {
            sieve[i] = i;
            primes[cp++] = i;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long nn = n;

        long long ans = 0;

        if (n < N) {
            while (n > 1) {
                int p = sieve[n];
                int e = 0;
                while (n > 1 && sieve[n] == p) {
                    e++;
                    n /= p;
                }
                ans += (long long)(nn / p) * e;
            }
        } else {
            for (int i = 0; i < cp && (long long)primes[i] * primes[i] <= n; i++) {
                if (n % primes[i] == 0) {
                    int e = 0;
                    while (n % primes[i] == 0) {
                        e++;
                        n /= primes[i];
                    }
                    ans += (long long)(nn / primes[i]) * e;
                }
            }
            if (n > 1) {
                ans += (long long)(nn / n);
            }
        }

        cout << ans << "\n";
    }

}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000+10;

int w[maxn+100];

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen("dat.txt","r",stdin);

    const int N = 2 * 1000 * 1000;
    vector <int> primes;
    vector <int> sieve(N);
    for (int i = 2; i < N; i++) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < N; j += i) {
                sieve[j] = i;
            }
        }
    }

    vector <int> cnt(N);

    for (int i = 2; i < N; i++) {
        cnt[i] = cnt[i - 1];
        if (sieve[i] == i) {
            cnt[i]++;
        }
    }

    long long n;
    cin >> n;

    vector <long long> p;
    for (int i = 2; (long long)i * i <= n; i++) {
        if (n % i == 0) {
            int e = 0;
            while (n % i == 0) {
                e++;
                n /= i;
            }
            if (e & 1) {
                p.push_back(i);
            }
        }
    }

    if (n > 1) {
        p.push_back(n);
    }

    if (p.size() == 0) {
        cout << "Vasya\n";
    } else {
        if (p.size() == 1) {
            cout << "David\n";
        } else {
            if (p.size() == 2) {
                cout << "David\n";
            } else {
                int xorSum = 0;
                for (auto x : p) {
                    if (x < N) {
                        xorSum ^= cnt[x];
                    }
                }
                // xorSum = xorSum ^ cnt[p.back()]
                assert(xorSum < N);
                if (p.back() > N) {
                    cout << "David\n";
                } else {
                    cout << (xorSum == 0 ? "Vasya" : "David") << "\n";
                }
            }
        }
    }
/*
    vector <bool> win(N);

    vector <int> grundy(N);
    vector <int> used(N);
    grundy[1] = 0;
    win[1] = false;
    for (int i = 2; i < N; i++) {
        vector <int> v;

        vector <int> ve;

        int x = i;
        while (x > 1) {
            int p = sieve[x];
            v.push_back(p);
            while (x > 1 && sieve[x] == p) {
                x /= p;
            }
        }

        for (auto p : v) {
            int y = i / p;
            used[ grundy[y] ] = i;

            if (!win[y]) {
                win[i] = true;
            }

            //cerr << ">>" << i << " " << p << "\n";

            for (int j = 0; primes[j] < p; j++) {
                used[ grundy[ y * primes[j]]] = i;
                if (!win[y * primes[j]]) {
                    win[i] = true;
                }
            }
        }
        grundy[i] = 0;
        while (used[grundy[i]] == i) {
            grundy[i]++;
        }

        if (!win[i]) {
            int x = i;
            int y = sqrt(x);
            while (y * y < x) {
                y++;
            }
            while (y * y > x) {
                y--;
            }
            if (y * y == x) {
                continue;
            }
            while (x > 1) {
                int p = sieve[x];
                int e = 0;
                while (x > 1 && sieve[x] == p) {
                    e++;
                    x /= p;
                }
                cerr << "(" << p << ", " << e << ") ";
            }
            cerr << "\n";
            cerr << i << " " << grundy[i] << "\n";
        }



    }
*/
}

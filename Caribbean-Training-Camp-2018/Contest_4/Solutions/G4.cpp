#include <bits/stdc++.h>
using namespace std;


const long long M = 1000 * 1000 * 1000 + 7;

inline void add(long long &a, long long b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

inline long long mul(long long a, long long b) {
    return (long long)a * b % M;
}


long long f(long long n, long long s) {
    if (n <= 0) {
        return 0;
    }

    long long ans = 0;

    for (long long b = 0; b < s; b++) {
        long long cnt = ((n + 1LL) / (1LL << (b + 1LL))) * (1LL << b);
        if (((n + 1LL) % (1LL << (b + 1LL))) >= (1LL << b)) {
            cnt += ((n + 1LL) % (1LL << (b + 1LL))) - (1LL << b);
        }

        //cerr << n << " " << s << " " << b << " " << cnt << "\n";

        add(ans, mul((1LL << (s - 1 - b)) % M, cnt));
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen( "dat.txt", "r", stdin );

    long long s, t;
    cin >> s >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;

        // cerr << f(l - 1, s) << " " << f(r, s) << "\n";

        long long ans = f(r, s);
        add(ans, M - f(l - 1, s));
        cout << ans << "\n";
    }
}

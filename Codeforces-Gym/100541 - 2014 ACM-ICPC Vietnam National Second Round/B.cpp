// 2014 ACM-ICPC Vietnam National Second Round
// 100541B

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000;

int solve1(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n / i) % MOD;
        ans %= MOD;
    }
    return ans;
}

int solve2(long long n) {
    if (n == 1) {
        return 1;
    }
    long long ans = n;
    long long sqrtn = sqrt(n);
        for (long long i = 2; i <= sqrtn; i++) {
            if ((n / i) <= sqrtn) {
                continue;
            }
            ans += (n / i) % MOD;
            ans %= MOD;
        }
        //cout << ans << "\n";
        for (long long i = 1; i <= sqrtn; i++) {
            //cout << i << " " << (n / i) << " " << (n / (i + 1)) << "\n";
            long long cnt = (n / i) - (n / (i + 1LL));
            ans += (cnt * i) % MOD;
            ans %= MOD;
        }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout << solve2(5); return 0;
    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve2(n) << "\n";
    }
}

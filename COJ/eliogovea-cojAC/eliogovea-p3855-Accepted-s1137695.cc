#include <bits/stdc++.h>

using namespace std;

inline int power(int x, int n, int m) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = (long long)res * x % m;
        }
        x = (long long)x * x % m;
        n >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    int t;
    string n;
    long long k;
    int r;

    cin >> t;
    while (t--) {
        cin >> n >> k >> r;
        int curr = 0;
        for (int i = 0; i < n.size(); i++) {
            curr = (long long)curr * 10LL % r;
            curr += (n[i] - '0');
            if (curr >= r) {
                curr -= r;
            }
        }
        int curp10 = power(10, n.size(), r);
        int ans = 0;
        int nextr;
        while (k) {
            if (k & 1LL) {
                ans = (long long)ans * curp10 % r;
                ans += curr;
                if (ans >= r) {
                    ans -= r;
                }
            }
            nextr = (long long)curr * curp10 % r;
            nextr += curr;
            if (nextr >= r) {
                nextr -= r;
            }
            curr = nextr;
            curp10 = (long long)curp10 * curp10 % r;
            k >>= 1LL;
        }

        cout << ans << "\n";
    }
}

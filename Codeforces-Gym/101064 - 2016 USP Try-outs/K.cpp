// 2016 USP Try-outs
// 101064K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int sz;

int s[MAXN];
int next[MAXN];
int l[MAXN];
int r[MAXN];

const double EPS = 1e-9;

inline bool check(int n, int p) {
    double res = 1.0;
    for (int i = 0; i < p; i++) {
        res *= ((double)n - (double)i) / (double)n;
    }
    res = 1.0 - res;
    //cerr << n << " " << p << " " << res << " " << (res > 0.5 + EPS) << "\n";
    return (res > 0.5 + EPS);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n;
    cin >> n;

    /*for (int i = 2; i <= n; i++) {
        check(n, i);
    }
    return 0;
    */
    int ans = n + 1;
    int lo = 2;
    int hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        //cout << lo << " " << hi << " " << mid << " " << check(n, mid) << "\n";
        //cout << mid << " " << check(n, mid) << "\n";
        if (check(n, mid)) {
            //cout << "asdfasfasdfs" << ans << "\n";
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

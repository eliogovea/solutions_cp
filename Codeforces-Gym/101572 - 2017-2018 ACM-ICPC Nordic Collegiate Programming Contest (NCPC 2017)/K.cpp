// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572K

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int T = 100 * 1000 + 10;

int b, n, e;
LL sb, sn, se;
int t;
LL c[T];
LL cc[T];

inline bool check(LL s) {
    for (int i = 0; i < t; i++) {
        cc[i] = (s + c[i] - 1LL) / c[i];
    }

    int ce = 0;
    int cn = 0;
    int cb = 0;

    for (int i = 0; i < t; i++) {
        int ue;
        int un;
        int ub;
        int sum = -1;

        if (ce + 2 <= e && cc[i] <= se + se) {
            if (sum == -1 || se + se < sum) {
                ue = 2;
                un = 0;
                ub = 0;
                sum = se + se;
            }
        }

        if (ce + 1 <= e && cn + 1 <= n && cc[i] <= se + sn) {
            if (sum == -1 || se + sn < sum) {
                ue = 1;
                un = 1;
                ub = 0;
                sum = se + sn;
            }
        }

        if (ce + 1 <= e && cb + 1 <= b && cc[i] <= se + sb) {
            if (sum == -1 || se + sb < sum) {
                ue = 1;
                un = 0;
                ub = 1;
                sum = se + sb;
            }
        }

        if (cn + 2 <= n && cc[i] <= sn + sn) {
            if (sum == -1 || sn + sn < sum) {
                ue = 0;
                un = 2;
                ub = 0;
                sum = sn + sn;
            }
        }

        if (cn + 1 <= n && cb + 1 <= b && cc[i] <= sn + sb) {
            if (sum == -1 || sn + sb < sum) {
                ue = 0;
                un = 1;
                ub = 1;
                sum = sn + sb;
            }
        }

        if (cb + 2 <= b && cc[i] <= sb + sb) {
            if (sum == -1 || sb + sb < sum) {
                ue = 0;
                un = 0;
                ub = 2;
                sum = sb + sb;
            }
        }

        if (sum == -1) {
            return false;
        }

        ce += ue;
        cn += un;
        cb += ub;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    cin >> b >> n >> e >> sb >> sn >> se;

    t = (b + n + e) / 2;
    for (int i = 0; i < t; i++) {
        cin >> c[i];
    }

    LL lo = 1;
    assert(check(lo));

    LL hi = lo;
    while (check(hi)) {
        hi *= 2;
    }

    LL ans = lo;

    while (lo <= hi) {
        LL mid = (lo + hi) / 2LL;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
}

// 2012-2013 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100685I

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL W, H, w, h;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> W >> H >> w >> h;
    LL x = W / w;
    LL y = H / h;
    LL ans = x * y;
    LL Wr = W % w;
    LL Hr = H % h;
    LL hh = Hr ? h / Hr : -1;
    LL ww = Wr ? w / Wr : -1;
    LL v1 = (Hr ? (x + hh - 1) / hh : 0) + (Wr ? (y + ww - 1) / ww : 0) + 1;
    LL v2 = (Hr ? (x + 1 + hh - 1) / hh : 0) + (Wr ? (y + ww - 1) / ww : 0);
    LL v3 = (Hr ? (x + hh - 1) / hh : 0) + (Wr ? (y + 1 + ww - 1) / ww : 0);
    ans += min(v1, min(v2, v3));
    cout << ans << "\n";
}

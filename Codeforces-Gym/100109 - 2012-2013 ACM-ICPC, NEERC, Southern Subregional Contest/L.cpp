// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109L

#include <bits/stdc++.h>

using namespace std;

inline int calc(int t, int t1, int t2) {
    return t / t1 + t / t2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, t1, t2;
    cin >> n >> t1 >> t2;
    int lo = 1;
    int hi = 1;
    while (calc(hi, t1, t2) < n) {
        hi <<= 1;
    }
    int anst = hi;
    int ansc = calc(hi, t1, t2);
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int cnt = calc(mid, t1, t2);
        if (cnt >= n) {
            anst = mid;
            ansc = cnt;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    //cerr << ansc << " " << anst << "\n";
    if (anst % t1 != 0 && anst % t2 == 0) {
        anst = anst + (t1 - (anst % t1));
        ansc++;
    } else if (anst % t1 == 0 && anst % t2 != 0) {
        anst = anst + (t2 - (anst % t2));
        ansc++;
    }
    cout << ansc << " " << anst << "\n";
}

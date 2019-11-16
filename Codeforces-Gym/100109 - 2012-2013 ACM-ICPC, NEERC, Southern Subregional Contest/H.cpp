// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109H

#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 100005;

int n, m, k;
int w[N], c[N];
int sw[N], sc[N];
int p[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
        sw[i] = sw[i - 1] + w[i];
        sc[i] = sc[i - 1] + c[i];
    }
    int ansCnt = 0;
    int ansVal = 0;
    int ansL = -1;
    int ansR = -1;
    for (int i = n; i >= m + 1; i--) {
        if (sw[i - m] * k < sw[i] - sw[i - m]) {
            break;
        }
        int lo = 0;
        int hi = i - m;
        int pos = 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if ((sw[i - m] - sw[mid]) * k >= sw[i] - sw[i - m]) {
                pos = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        p[i] = pos;
        int val = sc[n] - sc[i] + sc[pos];
        //cerr << i << " " << pos << " " << val << " " << pos + n - i << "\n";
        if (val > ansVal) {
            ansVal = val;
            ansCnt = pos + n - i;
            ansL = pos + 1;
            ansR = i;
        }
    }
    cout << ansCnt << " " << ansVal << "\n";
    if (ansCnt != 0) {
        string s;
        int x = ansR;
        while (ansL != 1 || ansR != n) {
            //cerr << ansL << " " << ansR << " " << p[ansR] << " " << p[ansR + 1] << "\n";
            if (ansL != 1 && ansL - 2 <= p[ansR]) {
                s += 'T';
                ansL--;
            } else if (ansR != n && ansL - 1 <= p[ansR + 1]) {
                s += 'H';
                ansR++;
            } else {
                assert(false);
            }
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}
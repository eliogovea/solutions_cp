// 2017-2018 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101611D

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1100;
struct problem{
    char state;
    int a, t;
};

int n, m, k;

string name[maxn];

typedef unsigned long long ULL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ULL y = 0;
    ULL cnt = 0;

    while (n--) {
        ULL x;
        cin >> x;
        if (x < 128ULL) {
            y = y + (x << cnt);
            if (!(y & 1ULL)) {
                cout << (y >> 1ULL) << "\n";
            } else {
                cout << "-" << ((y >> 1ULL) + 1ULL) << "\n";
            }
            y = 0;
            cnt = 0;
            continue;
        }
        x -= 128ULL;
        y = y + (x << cnt);
        cnt += 7;
    }

}

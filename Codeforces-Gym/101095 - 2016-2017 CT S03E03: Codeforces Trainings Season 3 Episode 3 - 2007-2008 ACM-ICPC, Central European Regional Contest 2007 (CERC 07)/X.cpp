// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095X

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int m;
    cin >> m;
    int id;
    int mn = -1;
    int a = 0, b, c;
    int bp = 0;
    int sp = 0;
    for (int i = 0; i < 12; i++) {
        int v;
        cin >> v;
        if (mn != -1 && mn < v && (m / mn) > 0) {
            if ((a < (m / mn) * v + (m % mn) - m) || ((a == (m / mn) * v + (m % mn) - m) && mn < bp)) {
                a = (m / mn) * v + (m % mn) - m;
                b = id;
                bp = mn;
                c = i;
                sp = v;
            }
        }
        if (mn == -1 || v < mn) {
            id = i;
            mn = v;
        }
    }
    if (a == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << b + 1 << " " << c + 1 << " " << a << "\n";
    }
}

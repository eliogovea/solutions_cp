// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090J

#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    long long n;
    cin >> n;

    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    long long ans = 0;
    long long x = n / 2LL;
    if (x >= 3) {
        ans += x * (x - 1) * (x - 2) / 6LL;
    }
    long long y = (n + 1LL) / 2LL;
    if (y >= 2 && x >= 1) {
        ans += y * (y - 1) * x / 2LL;
    }
    cout << ans << "\n";
}

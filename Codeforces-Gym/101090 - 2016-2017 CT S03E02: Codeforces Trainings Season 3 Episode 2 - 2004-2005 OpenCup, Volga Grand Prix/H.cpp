// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090H

#include <bits/stdc++.h>

using namespace std;

int k;
string s;
map <int, int> last;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> k >> s;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            int r = i % k;
            if (last.find(r) != last.end()) {
                ans1 = last[r] + 1;
                ans2 = i + 1;
                break;
            }
            last[(r + 1) % k] = i;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}

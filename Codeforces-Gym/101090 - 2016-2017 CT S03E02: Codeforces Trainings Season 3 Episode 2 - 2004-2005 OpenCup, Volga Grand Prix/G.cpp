// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090G

#include <bits/stdc++.h>

using namespace std;

int n, k;
int vals[1000005];
int freq[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> vals[i];
        freq[vals[i]]++;
    }
    bool ok = false;
    int v1, v2;
    for (int i = 1; i <= n && !ok; i++) {
        if (freq[i]) {
            for (int j = i + i; j <= n && !ok; j += i) {
                if (freq[j]) {
                    ok = true;
                    v1 = i;
                    v2 = j;
                }
            }
        }
    }
    if (!ok) {
        cout << "0 0\n";
    } else {
        int ans1 = -1;
        int ans2 = -1;
        for (int i = 1; i <= k; i++) {
            if (vals[i] == v1) {
                ans1 = i;
            }
            if (vals[i] == v2) {
                ans2 = i;
            }
        }
        if (ans1 > ans2) {
            swap(ans1, ans2);
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}

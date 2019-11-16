// 2016 USP Try-outs
// 101064C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int h, w;
    cin >> h >> w;

    vector <int> l(h);
    for (int i = 0; i < h; i++) {
        cin >> l[i];
    }
    vector <int> r(h);
    for (int i = 0; i < h; i++) {
        cin >> r[i];
    }
    int mn = w;
    for (int i = 0; i < h; i++) {
        mn = min(mn, w - l[i] - r[i]);
    }
    cout << mn / 2 << "." << 5 * (mn & 1) << "\n";
}

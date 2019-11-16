// 2016-2017 CT S03E04: Codeforces Trainings Season 3 Episode 4
// 101104K

#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x, y, id;
    pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

int cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

pt O;
bool cmp(const pt &a, const pt &b) {
    int c = cross(a - O, b - O);
    if (c != 0) {
        return (c > 0);
    }
    return a.id < b.id;
}

int n;
pt a[205], b[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> O.x >> O.y;
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y >> a[i + n].x >> a[i + n].y;
            a[i].id = 0;
            a[i + n].id = 0;
            if (cmp(a[i + n], a[i])) {
                swap(a[i], a[i + n]);
            }
            a[i].id = -1;
            a[i + n].id = 1;
        }
        sort(a, a + 2 * n, cmp);

        int cur = 0;
        int ans = 1;
        for (int i = 0; i < n + n; i++) {
            //cerr << a[i].id << " " << a[i].x << " " << a[i].y << "\n";
            if (a[i].id == -1) {
                cur++;
            } else {
                cur--;
            }
            //cerr << cur << "\n";
            if (cur == 0) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}

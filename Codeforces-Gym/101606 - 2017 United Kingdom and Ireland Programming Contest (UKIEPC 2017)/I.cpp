// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606I

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct point {
    LL x, y;
    point() {}
    point(LL _x, LL _y) : x(_x), y(_y) {}
};

inline double dist(const point & P, const point & Q) {
    double dx = P.x - Q.x;
    double dy = P.y - Q.y;
    return sqrt(dx * dx + dy * dy);
}

point operator - (const point & P, const point & Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

inline LL cross(const point & P, const point & Q) {
    return P.x * Q.y - P.y * Q.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    int h[n+1];
    for( int i = 1; i <= n; i++ ){
        cin >> h[i];
    }

    int sol = h[1];

    int t; cin >> t;

    for( int i = 2; i <= n; i++ ){
        if( t % h[i] < t % sol ){
            sol = h[i];
        }
    }

    cout << sol << '\n';
    return 0;



   /* int n;
    cin >> n;

    vector <point> pts(n);

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    double answer = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = true;
            LL mxc = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    LL c = cross(pts[k] - pts[i], pts[j] - pts[i]);
                    if (c < 0) {
                        ok = false;
                        break;
                    }
                    mxc = max(mxc, c);
                }
            }
            if (ok) {
                double h = (double)mxc / dist(pts[i], pts[j]);
                cerr << i << " " << j << " " << h << "\n";
                if (answer < 0.0 || h < answer) {
                    answer = h;
                }
            }
        }
    }

    cout.precision(13);
    cout << fixed << answer << "\n";*/
}

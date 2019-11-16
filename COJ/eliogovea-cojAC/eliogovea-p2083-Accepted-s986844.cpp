#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double EPS = 1e-12;

struct event {
    double angle;
    int type;
};

bool operator < (const event &a, const event &b) {
    if (abs(a.angle - b.angle) > EPS) {
        return a.angle < b.angle;
    }
    return a.type < b.type;
}

double getAngle(LL x, LL y) {
    if (x == 0) {
        if (y > 0) {
            return M_PI / 2.0;
        }
        return 3.0 * M_PI / 2.0;
    }
    if (y == 0) {
        if (x > 0) {
            return 0.0;
        }
        return M_PI;
    }
    double res = atan((double)abs(y) / (double)abs(x));
    if (x < 0 && y > 0) {
        res = M_PI - res;
    } else if (x < 0 && y < 0) {
        res = M_PI + res;
    } else if (x > 0 && y < 0) {
        res = 2.0 * M_PI - res;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n;
    LL r;
    while ((cin >> n >> r) && n) {
        vector <pair <LL, LL> > pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            vector <event> E;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    LL dx = pts[j].first - pts[i].first;
                    LL dy = pts[j].second - pts[i].second;
                    if (dx * dx + dy * dy == 4LL * r * r) {
                        double a = getAngle(dx, dy);
                        E.push_back((event) {a, -1});
                        E.push_back((event) {a, 1});
                    } else if (dx * dx + dy * dy < 4LL * r * r) {
                        double dist = sqrt(dx * dx + dy * dy) / 2.0;
                        double a = acos(dist / (double)r);
                        double b = getAngle(dx, dy);
                        double a1 = b - a;
                        double a2 = b + a;
                        if (a1 < -EPS) {
                            a1 += 2.0 * M_PI;
                        }
                        if (a2 >= 2.0 * M_PI - EPS) {
                            a2 -= 2.0 * M_PI;
                        }
                        if (a1 > a2 + EPS) {
                            cnt++;
                        }
                        E.push_back((event) {a1, -1});
                        E.push_back((event) {a2, 1});
                    }
                }
            }
            sort(E.begin(), E.end());
            int best = cnt;
            for (int i = 0; i < E.size(); i++) {
                if (E[i].type == -1) {
                    cnt++;
                } else {
                    cnt--;
                }
                best = max(best, cnt);
            }
            ans = max(ans, best + 1);
        }
        cout << "It is possible to cover " << ans << " points.\n";
    }

}
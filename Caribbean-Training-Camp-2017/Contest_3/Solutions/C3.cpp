#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(LL x) {
    if (x < 0) {
        return -1;
    }
    if (x > 0) {
        return 1;
    }
    return 0;
}

struct pt {
    LL x, y;
    pt() {}
    pt(LL _x, LL _y) : x(_x), y(_y) {}
    void read() {
        cin >> x >> y;
    }
};

pt operator - (const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

inline LL dot(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}

inline LL dist2(const pt &a, const pt &b) {
    return dot(a - b, a - b);
}

inline LL cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

/*
inline int halfPlane(pt &a) {
    if (a.y != 0) {
        return sign(a.y);
    }
    return sign(a.x);
}

inline bool operator < (const pt &a, const pt &b) {
    if (halfPlane(a) != halfPlane(b)) {
        return halfPlane(a) < halfPlane(b);
    }
    int c = sign(cross(a, b));
    if (c != 0) {
        return c > 0;
    }
    return dot(a, a) < dot(b, b);
}

inline bool isIn(int x, int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return (a <= x && x <= b);
}

inline bool contains(pt p, pt a, pt b) {
    if (abs(cross(a - p, b - p))) {
        return false;
    }
    return isIn(p.x, a.x, b.x) && isIn(p.y, a.y, b.y);
}

pt get(pt a) {
    if (a.y < 0) {
        a.x =
    }
}

int n;
pt a[1005], b[1005];

int solve(pt center, int id) {
    vector <pair <pt, int> > v;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (i == id) {
            continue;
        }
        if (contains(center, a[i], b[i])) {
            cnt++;
        } else {
            pt v1 = get(a[i] - center);
            pt v2 = get(b[i] - center);
            if (v1 < v2) {
                v.push_back(make_pair(v1, -1));
                v.push_back(make_pair(v2, 1));
            } else {
                v.push_back(make_pair(v2, -1));
                v.push_back(make_pair(v1, 1));
            }
        }
    }
    sort(v.begin(), v.end());
    int mx = cnt;
    for (int i = 0; )
}
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(14);

    //freopen("dat.txt", "r", stdin);

    pt a, b, c;
    LL r;
    a.read();
    b.read();
    c.read();
    cin >> r;

    LL cp = cross(b - a, c - a);
    LL d2 = dist2(a, b);
    if (cp * cp >= 4LL * r * r * d2) {
        double ans = sqrt((double)d2);
        cout << fixed << ans << "\n";
        return 0;
    }

    if (dist2(a, c) < dist2(b, c)) {
        swap(a, b);
    }
    if (abs(dot(c - a, b - a)) >= dist2(a, b)) {
        double ans = sqrt((double)d2);
        cout << fixed << ans << "\n";
        return 0;
    }

    double distToLine = abs((double)cp) / (sqrt((double)dist2(a, b)));

    double dist1 = sqrt((double)dist2(a, c));
    double angle1 = asin(distToLine / dist1);

    double dist21 = sqrt((double)dist2(b, c));
    double angle2 = asin(distToLine / dist21);

    double v1 = sqrt((double)dist2(a, c) - (double)r * r);
    double angle11 = acos((double)r / dist1);

    double v2 = sqrt((double)dist2(b, c) - (double)r * r);
    double angle22 = acos((double)r / dist21);

    double angle = M_PI - angle1 - angle11 - angle2 - angle22;
    double ans = v1 + v2 + r * angle;

    cout << fixed << ans << "\n";
}

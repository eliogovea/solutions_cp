#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
    int id;
    point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
};

point operator + (const point & P, const point & Q) {
    return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point & P, const point & Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point & P, long long k) {
    return point(P.x * k, P.y * k);
}

long long dot(const point & P, const point & Q) {
    return P.x * Q.x + P.y * Q.y;
}

long long cross(const point & P, const point & Q) {
    return P.x * Q.y - P.y * Q.x;
}

bool operator < (const point & P, const point & Q) {
    if (P.x != Q.x) {
        return P.x < Q.x;
    }
    return P.y > Q.y;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(3);

    // freopen("dat.txt", "r", stdin);

    int n;
    cin >> n;

    vector <point> pts(n);

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i + 1;
    }

    sort(pts.begin(), pts.end());

    vector <point> hull(n);
    int top = 0;

    for (int i = n - 1; i >= 0; i--) {
        while (top > 1 && cross(hull[top - 1] - hull[top - 2], pts[i] - hull[top - 2]) < 0) {
            top--;
        }
        hull[top++] = pts[i];
    }

    int last = 0;
    while (last + 1 < top && hull[last + 1].x + hull[last + 1].y >= hull[last].x + hull[last].y) {
        last++;
    }

    vector <int> ans(last + 1);
    for (int i = 0; i <= last; i++) {
        ans[i] = hull[i].id;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << "\n";
    }
}


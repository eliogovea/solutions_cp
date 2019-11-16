// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765E

#include <bits/stdc++.h>

using namespace std;

int n;

int l[4005];

struct pt {
    int x, y;
};

pt P[4005];

struct seg {
    pt a, b;
};

bool ver(seg a) {
    return (a.a.x == a.b.x);
}

bool hor(seg a) {
    return (a.a.y == a.b.y);
}

const int INF = 1e9;

bool inter(seg a, seg b, pt &res) {
    if (ver(a) && ver(b)) return false;
    if (hor(a) && hor(b)) return false;
    if (ver(a)) swap(a, b);
    if (a.a.x > a.b.x) swap(a.a.x, a.b.x);
    if (b.a.y > b.b.y) swap(b.a.y, b.b.y);
    //cout << "( " << a.a.x << ", " << a.a.y << ") -> (" << a.b.x << ", " << a.b.y << ")\n";
    //cout << "( " << b.a.x << ", " << b.a.y << ") -> (" << b.b.x << ", " << b.b.y << ")\n";
    //cout << (a.a.x <= b.a.x) << " " << (a.b.x >= b.a.x) << " " << (b.a.y <= a.a.y) << " " << (b.b.y >= a.a.y) << "\n";
    if (a.a.x <= b.a.x && a.b.x >= b.a.x && b.a.y <= a.a.y && b.b.y >= a.a.y) {
        res.x = b.a.x;
        res.y = a.a.y;
        return true;
    }
    return false;
}

int dist(pt p1, pt p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int best[4005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] + dist(P[i - 1], P[i]);
    }

    int ans = l[n - 1];

    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 2; j + 1 < n; j++) {
            pt in;
            if (inter((seg) {P[i], P[i + 1]}, (seg) {P[j], P[j + 1]}, in)) {
                int d1 = dist(P[i], in);
                int d2 = dist(P[j], in);
                int val = l[j] + d2 - l[i] - d1;
                ans = min(ans, val);
            }
        }
    }

    cout << ans << "\n";
}

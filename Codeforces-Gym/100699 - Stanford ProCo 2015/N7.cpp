// Stanford ProCo 2015
// 100699N7

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2005;

struct pt {
    LL x, y;
};

bool operator < (const pt &a, const pt &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool operator == (const pt &a, const pt &b) {
    return (a.x == b.x && a.y == b.y);
}

int n;
pt pts[N];

struct rt {
    LL a, b, c;
};

bool operator < (const rt &a, const rt &b) {
    if (a.a != b.a) return a.a < b.a;
    if (a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}

bool operator == (const rt &a, const rt &b) {
    return (a.a == b.a && a.b == b.b && a.c == b.c);
}

inline rt get(pt p1, pt p2) {
    LL dx = p1.x - p2.x;
    LL dy = p1.y - p2.y;
    LL a = -dy;
    LL b = dx;
    LL c = dx * p1.y - dy * p1.x;
    LL g = __gcd(abs(a), __gcd(abs(b), abs(c)));
    a /= g; b /= g; c /= g;
    if (a < 0) {
        a = -a; b = -b; c = -c;
    } else if (a == 0) {
        if (b < 0) {
            b = -b; c = -c;
        } else if (b == 0) {
            if (a < 0) {
                a = -a;
            }
        }
    }
    return (rt) {a, b, c};
}

int t;
pair<pt, rt> v[N * N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            LL dx = pts[j].x - pts[i].x;
            LL dy = pts[j].y - pts[i].y;
            rt r = get(pts[i], (pt) {pts[i].x - dy, pts[i].y + dx});
            v[t++] = make_pair((pt) {dx, dy}, r);
        }
    }
    sort(v, v + t);
    int l = 0;
    int r = 1;
    while (r < t) {
        if (!(v[l] == v[r])) {
            ans += 1LL * (r - l) * (r - l - 1LL) / 2LL;
            l = r;
        }
        r++;
    }
    ans += 1LL * (r - l) * (r - l - 1LL) / 2LL;
    cout << ans / 4LL << "\n";
}

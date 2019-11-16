#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline int sign(LL x) {
    if (x < 0) {
        return -1;
    }
    return (x > 0);
}

struct pt {
    LL x, y;
    pt() {}
    pt(LL _x, LL _y) {
        x = _x;
        y = _y;
    }
};

pt operator - (const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

LL cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

LL dot(const pt&a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}

LL dist2(const pt &a, const pt &b) {
    return dot(b - a, b - a);
}

pt O;
bool operator < (const pt &a, const pt &b) {
    int c = sign(cross(a - O, b - O));
    if (c != 0) {
        return c == 1;
    }
    return dist2(a, O) < dist2(b, O);
}

const int N = 100005;

int n;
pt p[N];
pt ch[N]; int sz;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    LL ans = 0;
    if (n <= 2000) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, abs(cross(p[i], p[j])));
            }
        }
        cout << ans << "\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x)) {
            swap(p[0], p[i]);
        }
    }

    O = p[0];
    sort(p + 1, p + n);
    sz = 0;
    for (int i = 0; i < n; i++) {
        while (sz >= 2 && sign(cross(ch[sz - 1] - ch[sz - 2], p[i] - ch[sz - 2])) <= 0) {
            sz--;
        }
        ch[sz++] = p[i];
    }
    if (sz <= 2000) {
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                ans = max(ans, abs(cross(ch[i], ch[j])));
            }
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i < sz; i++) {
        ans = max(ans, abs(cross(ch[i], ch[(i + 1) % sz])));
    }
    int pos = 1;
    for (int i = 0; i < sz; i++) {
        while (((pos + 1) % sz) != i && cross(ch[i], ch[(pos + 1) % sz]) >= 0LL) {
            pos++;
        }
        int lo = i + 1;
        if (cross(ch[i], ch[lo % sz]) == 0) {
            lo++;
        }
        int hi = pos;
        int pp = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (cross(ch[i], ch[mid % sz]) >= cross(ch[i], ch[((mid - 1 + sz) % sz)])) {
                pp = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ans = max(ans, abs(cross(ch[i], ch[pp % sz])));
    }
    for (int i = 0; i < sz; i++) {
        ch[i].x = -ch[i].x;
        ch[i].y = -ch[i].y;
    }
    pos = 2;
    for (int i = 1; i != 0; i = (i + 1) % sz) {
        while (((pos + 1) % sz) != i && cross(ch[i], ch[(pos + 1) % sz]) >= 0LL) {
            pos++;
        }
        int lo = i + 1;
        if (cross(ch[i], ch[lo % sz]) == 0) {
            lo++;
        }
        int hi = pos;
        int pp = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (cross(ch[i], ch[mid % sz]) >= cross(ch[i], ch[((mid - 1 + sz) % sz)])) {
                pp = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ans = max(ans, abs(cross(ch[i], ch[pp % sz])));
    }
    cout << ans << "\n";
}

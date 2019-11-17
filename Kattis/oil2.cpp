// https://icpc.kattis.com/problems/oil2

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2005;

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
    int x, y;
};

pt operator - (const pt &a, const pt &b) {
    return (pt) {a.x - b.x, a.y - b.y};
}

LL cross(const pt &a, const pt &b) {
    return (LL)a.x * b.y - (LL)a.y * b.x;
}

LL norm2(const pt &a) {
    return (LL)a.x * a.x + (LL)a.y * a.y;
}

bool operator < (const pt &a, const pt &b) {
    int c = sign(cross(a, b));
    if (c != 0) {
        return c > 0;
    }
    return norm2(a) < norm2(b);
}

struct event {
    pt p;
    int value;
};

bool operator < (const event &a, const event &b) {
    int c = sign(cross(a.p, b.p));
    if (c != 0) {
        return c > 0;
    }
    return a.value > b.value;
}

int n;
int x0[N], x1[N], y[N];

LL solve(pt P) {
    vector <event> E;
    for (int i = 0; i < n; i++) {
        if (y[i] == P.y) {
            continue;
        }
        if (y[i] > P.y) {
            pt P0 = (pt) {x0[i], y[i]} - P;
            pt P1 = (pt) {x1[i], y[i]} - P;
            if (P1 < P0) {
                swap(P0, P1);
            }
            E.push_back((event) {P0, abs(x0[i] - x1[i])});
            E.push_back((event) {P1, -abs(x0[i] - x1[i])});
        } else {
            pt P0 = P - (pt) {x0[i], y[i]};
            pt P1 = P - (pt) {x1[i], y[i]};
            if (P1 < P0) {
                swap(P0, P1);
            }
            E.push_back((event) {P0, abs(x0[i] - x1[i])});
            E.push_back((event) {P1, -abs(x0[i] - x1[i])});
        }
    }
    sort(E.begin(), E.end());
    LL cur = 0;
    LL best = 0;
    for (int i = 0; i < E.size(); i++) {
        cur += (LL)E[i].value;
        assert(cur >= 0);
        best = max(best, cur);
    }
    return best;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x0[i] >> x1[i] >> y[i];
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, solve((pt) {x0[i], y[i]}) + abs(x0[i] - x1[i]));
        ans = max(ans, solve((pt) {x1[i], y[i]}) + abs(x0[i] - x1[i]));
    }
    cout << ans << "\n";
}

// https://icpc.kattis.com/problems/airport

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

typedef long long LL;

inline int sign(const LL x) {
    return (x < 0) ? -1 : (x > 0);
}

struct point {
    LL x, y;
    point() {}
    point(LL _x, LL _y) : x(_x), y(_y) {}
};

bool operator < (const point &P, const point &Q) {
    if (P.y != Q.y) {
        return P.y < Q.y;
    }
    return P.x < Q.x;
}

bool operator == (const point &P, const point &Q) {
    return !(P < Q) && !(Q < P);
}

point operator - (const point &P, const point &Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

inline LL cross(const point &P, const point &Q) {
    return P.x * Q.y - P.y * Q.x;
}

vector <point> normalize(vector <point> pts) {
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    while (pts.size() > 1 && pts.back() == pts[0]) {
        pts.pop_back();
    }
    rotate(pts.begin(), min_element(pts.begin(), pts.end()), pts.end());
    int pos = 2;
    for (int i = 2; i < pts.size(); i++) {
        if (sign(cross(pts[pos - 1] - pts[pos - 2], pts[i] - pts[pos - 2])) == 0) {
            pos--;
        }
        pts[pos++];
    }
    if (sign(cross(pts[pos - 1] - pts[pos - 2], pts[0] - pts[pos - 2])) == 0) {
        pos--;
    }
    pts.resize(pos);
    /// points in counter clock wise
    LL area = 0;
    for (int i = 0; i < pts.size(); i++) {
        area += cross(pts[i], pts[(i + 1 == pts.size()) ? 0 : i + 1]);
    }
    if (area < 0) {
        reverse(pts.begin(), pts.end());
    }
    return pts;
}

const LD EPSILON = 1e-9;

inline int sign(const LD x) {
    return (x < -EPSILON) ? -1 : (x > EPSILON);
}

struct point_LD {
    LD x, y;
    point_LD() {}
    point_LD(LD _x, LD _y) : x(_x), y(_y) {}
};

bool operator < (const point_LD &P, const point_LD &Q) {
    if (P.y != Q.y) {
        return P.y < Q.y;
    }
    return P.x < Q.x;
}

point_LD get(point P) {
    return point_LD((LD)P.x, (LD)P.y);
}

point_LD operator + (const point_LD &P, const point_LD &Q) {
    return point_LD(P.x + Q.x, P.y + Q.y);
}

point_LD operator - (const point_LD &P, const point_LD &Q) {
    return point_LD(P.x - Q.x, P.y - Q.y);
}

point_LD operator * (const point_LD &P, LD k) {
    return point_LD(P.x * k, P.y * k);
}

inline LD dot(const point_LD &P, const point_LD &Q) {
    return P.x * Q.x + P.y * Q.y;
}

inline LD cross(const point_LD &P, const point_LD &Q) {
    return P.x * Q.y - P.y * Q.x;
}

inline LD dist(const point_LD &P, const point_LD &Q) {
    return sqrtl(dot(P - Q, P - Q));
}

inline point_LD intersect(const point_LD &A, const point_LD &B, const point_LD &C, const point_LD &D) {
    LD t = cross(C - A, C - D) / cross(B - A, C - D);
    return A * (1.0 - t) + B * t;
    // return A + (B - A) * (cross(C - A, C - D) / cross(B - A, C - D));
}

struct comparator {
    point_LD A, B;
    comparator(point_LD _A, point_LD _B) {
        A = _A;
        B = _B;
    }
    bool operator () (const point_LD &P, const point_LD &Q) {
        return dot(P - A, B - A) < dot(Q - A, B - A);
    }
};

LD solve(const vector <point> &pts, const point &P, const point &Q) {
    int n = pts.size();

    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = sign(cross(Q - P, pts[i] - P));
    }

    vector <point_LD> v;

    for (int i = 0; i < n; i++) {
        if (s[i] != 0) {
            int ne = (i + 1 == n) ? 0 : i + 1;
            if (s[ne] * s[i] == -1) {
                v.push_back(intersect(get(P), get(Q), get(pts[i]), get(pts[ne])));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            int ne = (i + 1 == n) ? 0 : i + 1;
            int pr = (i == 0) ? n - 1 : i - 1;
            if (s[ne] == s[pr]) {
                continue;
            }
            if (s[pr] == 0) {
                if (sign(cross(pts[i] - pts[pr], pts[ne] - pts[pr])) == 1) {
                    v.push_back(get(pts[i]));
                }
            } else if (s[ne] == 0) {
                if (sign(cross(pts[ne] - pts[i], pts[pr] - pts[i])) == 1) {
                    v.push_back(get(pts[i]));
                }
            } else {
                v.push_back(get(pts[i]));
            }
        }
    }

    sort(v.begin(), v.end(), comparator(get(P), get(Q)));
    LD result = 0.0;
    for (int i = 0; i + 1 < v.size(); i += 2) {
        result = max(result, dist(v[i], v[i + 1]));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input-timus-1955.txt", "r", stdin);

    int n;
    cin >> n;

    vector <point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // pts = normalize(pts);
    // n = pts.size();

    LD answer = 0.0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, dist(get(pts[i]), get(pts[i + 1 == n ? 0 : i + 1])));
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            answer = max(answer, solve(pts, pts[i], pts[j]));
        }
    }
    cout.precision(14);
    cout << fixed << answer << "\n";

}

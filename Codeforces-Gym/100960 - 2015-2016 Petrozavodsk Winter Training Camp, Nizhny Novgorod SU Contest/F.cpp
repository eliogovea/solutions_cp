// 2015-2016 Petrozavodsk Winter Training Camp, Nizhny Novgorod SU Contest
// 100960F

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct pt {
    LL x, y;
    pt() {}
    pt(LL _x, LL _y) : x(_x), y(_y) {}
};

pt operator - (const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}

LL dot(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}

LL cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

LL dist2(const pt &a, const pt &b) {
    LL dx = a.x - b.x;
    LL dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool check(pt P, pt Q, pt R, LL lm, LL lg) {
    LL D = dist2(P, Q);
    if (D > 2LL * lg * 2LL * lg) {
        return false;
    }
    if (dot(P - Q, R - Q) >= 0LL && dot(P - Q, R - Q) * dot(P - Q, R - Q) > dist2(Q, P) * lg * lg) {
        return false;
    }
    swap(P, Q);
    if (dot(P - Q, R - Q) >= 0LL && dot(P - Q, R - Q) * dot(P - Q, R - Q) > dist2(Q, P) * lg * lg) {
        return false;
    }
    if (cross(P - Q, R - Q) * cross(P - Q, R - Q) > lm * lm * dist2(Q, P)) {
        return false;
    }
    return true;
}

bool check2(pt P, pt Q, pt R, LL lm, LL lg) {
    if (dist2(P, Q) > lm * lm) {
        return false;
    }
    if (dot(P - Q, R - Q) <= 0LL) {
        return false;
    }

    if (dot(P - Q, R - Q) < dist2(P, Q)) {
        return false;
    }
    if (dot(P - Q, R - Q) * dot(P - Q, R - Q) > dist2(P, Q) * lm * lm) {
        return false;
    }
    if (cross(P - Q, R - Q) * cross(P - Q, R - Q) > dist2(P, Q) * lg * lg) {
        return false;
    }
    return true;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int t;
    LL lm, lg;
    pt P, Q, R;

    cin >> t;
    while (t--) {
        cin >> lm >> lg;
        cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y;

        if (cross(Q - P, R - P) == 0LL) {
            if (max(dist2(P, Q), max(dist2(Q, R), dist2(R, P))) <= max(lm, 2LL * lg) * max(lm, 2LL * lg)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        if (check2(P, Q, R, lm, lg) || check2(Q, P, R, lm, lg) ||
            check2(Q, R, P, lm, lg) || check2(R, Q, P, lm, lg) ||
            check2(P, R, Q, lm, lg) || check2(R, P, Q, lm, lg)) {
            cout << "YES\n";
            continue;
        }

        if (check(P, Q, R, lm, lg) || check(P, R, Q, lm, lg) || check(Q, R, P, lm, lg)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

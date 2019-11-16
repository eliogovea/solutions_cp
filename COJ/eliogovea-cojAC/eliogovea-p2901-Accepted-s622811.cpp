#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct pt {
    int x, y, z;
    pt() {}
    pt(int a, int b, int c) : x(a), y(b), z(c) {}
    void norm() {
        if (x == 0 && y == 0 && z == 0) return;
        int xx = abs(x), yy = abs(y), zz = abs(z), g = __gcd(xx, __gcd(yy, zz));
        x /= g;
        y /= g;
        z /= g;
        if (x < 0) {x *= -1; y *= -1; z *= -1;}
        else if (x == 0) {
            if (y < 0) {y *= -1; z *= -1;}
            else if (y == 0) {
                if (z < 0) z *= -1;
            }
        }
    }
    bool operator < (const pt &P) const {
        if (x != P.x) return x < P.x;
        if (y != P.y) return y < P.y;
        return z < P.z;
    }
};

int n, sol;
vector<pt> pts;
map<pt, int> m;
map<pt, int>::iterator it;

int main()
{
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("%d\n", n);
        return 0;
    }
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        pts.push_back(pt(a, b, c));
    }

    for (int i = 0; i < n; i++) {
        m.clear();
        pt p;
        for (int j = 0; j < n; j++)
            if (i != j) {
                p = pt(pts[j].x - pts[i].x, pts[j].y - pts[i].y, pts[j].z - pts[i].z);
                p.norm();
                m[p]++;
            }
        for (it = m.begin(); it != m.end(); it++)
            sol = max(sol, it->second + 1);
    }

    printf("%d\n", sol);

    return 0;
}

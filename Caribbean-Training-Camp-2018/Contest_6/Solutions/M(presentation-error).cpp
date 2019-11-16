#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
};

point operator + (const point & P, const point & Q) {
    return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point & P, const point & Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point & P, double k) {
    return point(k * P.x, k * P.y);
}

inline double dot(const point & P, const point & Q) {
    return P.x * Q.x + P.y * Q.y;
}

inline double cross(const point & P, const point & Q) {
    return P.x * Q.y - P.y * Q.x;
}

inline double dist(const point & P, const point & Q) {
    return sqrt(dot(P - Q, P - Q));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    int a, b, c;
    cin >> a >> b >> c;

    vector <point> pts = {point(0, 0), point(c, 0), point(a, b)};

    double area = -abs(0.5 * cross(pts[1] - pts[0], pts[2] - pts[0]));

    double len = dist(pts[0], pts[1]) + dist(pts[1], pts[2]) + dist(pts[2], pts[0]);

    for (int i = 0; i < 3; i++) {
        {
            point P = pts[i];
            point A = pts[i];
            point B = pts[(i + 1) % 3];
            point C = pts[(i + 2) % 3];

            point v1 = (B - A) * (1.0 / dist(B, A));
            point v2 = (C - B) * (1.0 / dist(C, B));

            double tQ = (0.5 * len - dist(A, B));
            point Q = B + v2 * tQ;

            double a = v2.x * v1.y - v2.y * v1.x;
            double b = -v2.x * (B.y - P.y) - v1.y * (B.x - Q.x) + v2.y * (B.x - P.x) + v1.x * (B.y - Q.y);
            double c = (B.x - Q.x) * (B.y - Q.y) - (B.x - P.x) * (B.y - Q.y) - area;

            double d2 = b * b - 4.0 * a * c;

            if (d2 < -EPS) {
                continue;
            }

            double t1 = (-b - sqrt(d2)) / (2.0 * a);
            double t2 = (-b + sqrt(d2)) / (2.0 * a);

            double maxt = min(dist(A, B), dist(Q, C));

            if (-EPS <= t1 && t1 <= maxt + EPS) {
                point PP = P + v1 * t1;
                point QQ = Q + v2 * t1;

                cout << fixed << PP.x << " " << fixed << PP.y << "\n";
                cout << fixed << QQ.x << " " << fixed << QQ.y << "\n";

                return 0;
            }

            if (-EPS <= t2 && t2 <= maxt + EPS) {
                point PP = P + v1 * t2;
                point QQ = Q + v2 * t2;

                cout << fixed << PP.x << " " << fixed << PP.y << "\n";
                cout << fixed << QQ.x << " " << fixed << QQ.y << "\n";

                return 0;
            }
        }
/*
        {
            point P = pts[i];
            point A = pts[i];
            point B = pts[(i + 1) % 3];
            point C = pts[(i + 2) % 3];

            point v1 = (C - A) / dist(C, A);
            point v2 = (B - C) / dist(C, B);

            double tQ = (0.5 * len - dist(A, C));
            point Q = C + v2 * tQ;

            double a = v2.x * v1.y - v2.y * v1.x;
            double b = -v2.x * (B.y - P.y) - v1.y * (B.x - Q.x) + c2.y * (B.x - P.x) + v1.x * (B.y - Q.y);
            double c = (B.x - Q.x) * (B.y - Q.y) - (B.x - P.x) * (B.x - Q.x);

            double d2 = b * b - 4.0 * a * c;

            if (d2 < -EPS) {
                continue;
            }

            double t1 = (-b - sqrt(d2)) / (2.0 * a);
            double t2 = (-b + sqrt(d2)) / (2.0 * a);

            double maxt = min(dist(A, C), dist(Q, B));

            if (-EPS <= t1 && t1 <= maxt) {
                point PP = P + t1 * v1;
                point QQ = Q + t1 * v2;

                cout << fixed << PP.x << " " << fixed << PP.y << "\n";
                cout << fixed << QQ.x << " " << fixed << QQ.y << "\n";

                return 0;
            }

            if (-EPS <= t2 && t2 <= maxt) {
                point PP = P + t2 * v1;
                point QQ = Q + t2 * v2;

                cout << fixed << PP.x << " " << fixed << PP.y << "\n";
                cout << fixed << QQ.x << " " << fixed << QQ.y << "\n";

                return 0;
            }
        }
*/

    }
}

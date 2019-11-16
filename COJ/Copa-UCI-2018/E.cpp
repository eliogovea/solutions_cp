#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

point operator + (const point & P, const point & Q) {
    return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point & P, const point & Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

point operator * (const point & P, double k) {
    return point(P.x * k, P.y * k);
}

double dot(const point & P, const point & Q) {
    return P.x * Q.x + P.y * Q.y;
}

double cross(const point & P, const point & Q) {
    return P.x * Q.y - P.y * Q.x;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(3);

    point P, A, B;

    cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;

    double t = dot(P - A, B - A) / dot(B - A, B - A);

    point Q = A + (B - A) * t;
    double d = sqrt(dot(P - Q, P - Q));

    cout << fixed << Q.x << " " << fixed << Q.y << " " << fixed << d << "\n";
}


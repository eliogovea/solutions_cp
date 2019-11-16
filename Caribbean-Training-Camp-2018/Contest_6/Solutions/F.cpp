#include <bits/stdc++.h>

using namespace std;
/*
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

point operator + (const point & P, double) {
    return point(k * P.x, k * P.y);
}

inline double dot(const point & P, const point & Q) {
    return P.x * Q.x + P.y * Q.y;
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

    vector <point> P = {point()}
}
*/

inline char val(int n) {
    if (n < 10) {
        return '0' + n;
    }
    return 'A' + (n - 10);
}

inline int charVal(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    if ('A' <= c && c <= 'Z') {
        return 10 + (c - 'A');
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    const int INF = 2 * 1000 * 1000 * 1000;

    vector <long long> f;
    f.push_back(1);
    while (f.back() < INF) {
        f.push_back(f.back() * (long long)f.size());
    }

    string s;
    cin >> s;

    long long sum = 0;

    int sign = 1;
    for (int i = 0, j = 0; i < s.size(); i = j) {
        while (j < s.size() && charVal(s[j]) != -1) {
            j++;
        }

        for (int p = j - 1; p >= i; p--) {
            sum  += (long long)sign * f[j - p] * (long long)charVal(s[p]);
        }
        if (j < s.size()) {
            sign = (s[j] == '+' ? 1 : -1);
            j++;
        }
    }

    int pf = f.size() - 1;

    while (f[pf] > sum) {
        pf--;
    }

    int len = pf;

    string ans;
    for (int i = 0; i < len; i++) {
        ans += '0';
        if (sum == 0) {
            continue;
        }

        if (f[len - i] > sum) {
            continue;
        }
        ans[i] = val(sum / f[len - i]);
        sum %= f[len - i];
    }

    cout << ans << "\n";
}

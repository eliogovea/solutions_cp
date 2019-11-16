// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486F

#include <bits/stdc++.h>

using namespace std;

struct matrix {
    double m[3][3];
    matrix(double x) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = 0.0;
                if (i == j) m[i][j] = x;
            }
        }
    }
    double * operator [] (int x) {
        return m[x];
    }
    const double * operator [] (const int x) const {
        return m[x];
    }
};

matrix operator * (const matrix &a, const matrix &b) {
    matrix res(0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

matrix power(matrix x, int n) {
    matrix res(1);
    while (n) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

int x, y, n;
double r;

const double eps = 1e-10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    while (cin >> x >> y >> n >> r) {
        if (x == 0 && y == 0 && n == 0 && r == 0.0) break;
        matrix M(0);
        M[0][0] = (1200.0 + r) / (1200.0);
        M[0][1] = -1.0;
        M[1][0] = 0.0;
        M[1][1] = 1.0;
        M = power(M, 12 * n);

        double X = (double)x * M[0][0] + y * M[0][1];
        //cout << X << " ";
        cout << (X <= eps ? "YES" : "NO") << "\n";
    }
}

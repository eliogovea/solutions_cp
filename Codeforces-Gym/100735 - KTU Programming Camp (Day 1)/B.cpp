// KTU Programming Camp (Day 1)
// 100735B

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000009;

inline void add(LL &a, LL b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

inline LL mul(LL a, LL b) {
    return (a * b) % MOD;
}

int SZ;

struct matrix {
    LL mat[22][22];
    LL * operator [] (int x) {
        return mat[x];
    }
    const LL * operator [] (int x) const {
        return mat[x];
    }
    matrix(LL v) {
        for (int i = 0; i < SZ; i++) {
            for (int j = 0; j < SZ; j++) {
                mat[i][j] = 0;
                if (i == j) {
                    mat[i][j] = v;
                }
            }
        }
    }
};

matrix operator * (const matrix &a, const matrix &b) {
    matrix res(0);
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                add(res[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}

matrix power(matrix x, long long n) {
    matrix res(1);
    while (n) {
        if (n & 1LL) {
            res = res * x;
        }
        x = x * x;
        n >>= 1LL;
    }
    return res;
}

long long f[25], k[25];

int n, c;
long long m;

void print(matrix M) {
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> k[i];
    }
    if (m <= n) {
        cout << f[m] << "\n";
        return 0;
    }
    SZ = n;
    matrix M(0);
    for (int i = 0; i < c; i++) {
        M[0][k[i] - 1]++;
    }
    for (int i = 1; i < n; i++) {
        M[i][i - 1]++;
    }
    //print(M);
    M = power(M, m - n);
    //print(M);
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        add(ans, mul(f[n - i], M[0][i]));
    }
    cout << ans << "\n";
}

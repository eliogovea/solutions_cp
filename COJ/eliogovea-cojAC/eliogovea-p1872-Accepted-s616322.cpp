#include <cstdio>

typedef long long ll;
const int SIZE = 2;
const ll mod = 1000007;

struct mat {
    ll m[SIZE][SIZE];
    mat(ll a, ll b, ll c, ll d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
};

const mat N(0, 0, 0, 0), I(1, 0, 0, 1), F(1, 1, 1, 0);

mat mult(mat &a, mat &b) {
    mat r = N;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
                r.m[i][j] = (r.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
    return r;
}

mat exp(mat m, ll n) {
    mat r= I;
    while (n) {
        if (n & 1ll) r = mult(r, m);
        m = mult(m, m);
        n >>= 1ll;
    }
    return r;
}

ll tc, n;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lld", &n);
        mat M = exp(F, n + 1);
        printf("%lld\n", M.m[0][0] % mod);
    }
}

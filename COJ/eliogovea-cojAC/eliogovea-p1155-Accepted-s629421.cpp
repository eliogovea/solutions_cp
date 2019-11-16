#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10000;

const int SIZE = 3;

struct mat {
	ll m[SIZE + 1][SIZE + 1];
	void idem() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = (ll)(i == j);
	}
	void nul() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = 0;
	}
	void ut(ll a, ll b, ll c) {
		m[0][0] = a; m[0][1] = 1; m[0][2] = 0;
		m[1][0] = b; m[1][1] = 0; m[1][2] = 1;
		m[2][0] = c; m[2][1] = 0; m[2][2] = 0;
	}
	mat operator * (const mat &M) {
		mat r;
		r.nul();
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < SIZE; k++)
					r.m[i][j] = (r.m[i][j] + ((m[i][k] * M.m[k][j]) % mod)) % mod;
		return r;
	}
};

mat exp(mat x, ll n) {
	mat r;
	r.idem();
	while (n) {
		if (n & 1ll) r = r * x;
		x = x * x;
		n >>= 1ll;
	}
	return r;
}

ll f[4], a, b, c, n, sol;
mat M;

int main() {
    ios::sync_with_stdio(false);
    cin >> f[1] >> f[2] >> f[3] >> c >> b >> a >> n;
    if (n <= 3) cout << f[n] << '\n';
    else {
        M.ut(a, b, c);
        M = exp(M, n - 3ll);
        sol = (f[3] * M.m[0][0]) % mod;
        sol += (f[2] * M.m[1][0]) % mod; if (sol >= mod) sol -= mod;
        sol += (f[1] * M.m[2][0]) % mod; if (sol >= mod) sol -= mod;
        cout << sol << '\n';
    }
}

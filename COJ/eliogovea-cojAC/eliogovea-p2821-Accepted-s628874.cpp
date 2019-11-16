#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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
	void ut(ll x) {
		m[0][0] = 1; m[0][1] = x; m[0][2] = x;
		m[1][0] = 0; m[1][1] = x; m[1][2] = x;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = x;
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
	void print() {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++)
        printf("%lld ", m[i][j]);
      printf("\n");
      }
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

int tc;
ll n, x;
mat M, r;

int main() {
    std::ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
        cin >> n >> x;
        M.ut(x);
        r = exp(M, n);
        //r.print();
        cout << r.m[0][2] << '\n';
	}
}

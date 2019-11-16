#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int SIZE = 4;
const ll mod = 1000000007;

struct matrix {
	ll m[SIZE + 1][SIZE + 1];
	void init() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = 0;
	}
	void ide() {
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				m[i][j] = (i == j);
	}
	void ut(ll n, ll c, ll p) {
		m[0][0] = 1; m[0][1] = n; m[0][2] = c; m[0][3] = p;
		m[1][0] = 0; m[1][1] = p; m[1][2] = c; m[1][3] = n;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = c + n + p; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = n; m[3][2] = c; m[3][3] = p;
	}
	matrix operator * (const matrix &A) {
		matrix r;
		r.init();
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < SIZE; k++)
					r.m[i][j] = (r.m[i][j] + ((m[i][k] * A.m[k][j]) % mod)) % mod;
		return r;
	}
	matrix exp(ll n) {
		matrix r, x = *this;
		r.ide();
		while (n) {
			if (n & 1ll) r = r * x;
			x = x * x;
			n >>= 1ll;
		}
		return r;
	}
} a, b;

int tc;
ll t, k, x, n, p, c, sn, sc, sp;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> t >> k;
		n = p = c = 0ll;
		while (t--) {
			cin >> x;
			if (x > 0ll) p++;
			if (x == 0ll) c++;
			if(x < 0ll) n++;
		}
		a.ut(n, c, p);
		b = a.exp(k);
		cout << b.m[0][3] << ' ' << b.m[0][1] << ' ' << b.m[0][2] << '\n';
	}
}

#include <cstdio>

using namespace std;

typedef long long ll;

const ll MAXN = 11, mod = 1000000007;

int tc, n, m, q;

struct matrix {
	ll m[MAXN + 1][MAXN + 1];
	void init() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = 0;
	}
	void ide() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = (i == j);
	}
	matrix operator * (const matrix &a) {
		matrix r;
		r.init();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					r.m[i][j] = (r.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
		return r;
	}
	matrix exp(ll e) {
		matrix r, x = *this;
		r.ide();
		while (e) {
			if (e & 1ll) r = r * x;
			x = x * x;
			e >>= 1ll;
		}
		return r;
	}
} M;

int main() {
  //freopen("e.in", "r", stdin);
	scanf("%d", &tc);
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d%d", &n, &m);
		M.init();
		for (int i = 0, a, b; i < m; i++) {
			scanf("%d%d", &a, &b);
			M.m[a - 1][b - 1] = 1ll;
		}
		printf("Case %d:\n", cas);
		scanf("%d", &q);
		int a, b; ll c;
		for (int i = 0; i < q; i++) {
			scanf("%d%d%lld", &a, &b, &c);
			printf("%lld\n", M.exp(c).m[a - 1][b - 1]);
		}
	}
}

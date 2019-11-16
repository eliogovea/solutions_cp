#include <cstdio>
using namespace std;

typedef long long ll;

const ll mod = 10007;

const int SIZE = 3;

struct mat {
	ll m[SIZE][SIZE];
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
	void ut() {
		m[0][0] = 2; m[0][1] = 1; m[0][2] = 0;
		m[1][0] = 2; m[1][1] = 0; m[1][2] = 1;
		m[2][0] = 2; m[2][1] = 0; m[2][2] = 0;
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

int n;
mat M;

int main() {
	M.ut();
	while (scanf("%d", &n) && n) {
		mat res = exp(M, n);
		//res.print();
		printf("%lld\n", (res.m[0][0] + res.m[0][1] + res.m[0][2]) % mod);
	}
}

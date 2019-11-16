#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 98765431;
 
const int SIZE = 2;
 
struct matrix {
	ll m[SIZE + 1][SIZE + 1];
	ll * operator [] (int x) {
		return m[x];
	}
	const ll * operator [] (const int x) const {
		return m[x];
	}
	void O() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = 0;
			}
		}
	}
	void I() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				m[i][j] = (i == j);
			}
		}
	}
};
 
matrix operator * (const matrix &a, const matrix &b) {
	matrix res;
	res.O();
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				if (res[i][j] > mod) {
					res[i][j] -= mod;
				}
			}
		}
	}
	return res;
}
 
matrix power(matrix x, ll n) {
	matrix res;
	res.I();
	while (n) {
		if (n & 1LL) {
			res = res * x;
		}
		x = x * x;
		n >>= 1LL;
	}
	return res;
}
 
ll n, t, c[50005], sum;
matrix a;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
		if (sum > mod) {
			sum -= mod;
		}
	}
	a[0][0] = -1 + mod;
	a[0][1] = 1;
	a[1][0] = 0;
	a[1][1] = n - 1;
	a = power(a, t);
	for (int i = 0; i < n; i++) {
		ll ans = (((a[0][0] * c[i]) % mod) + ((a[0][1] * sum) % mod)) % mod;
		cout << ans << "\n";
	}
}
 
/*
	Sea T(n) la suma de todos los numeros de la vacas despues
	de n pasos
	Sea C(n) el numero de cierta vaca despues de n pasos
	Como la vaca toma el numeros que es la suma de todas las otras vacas
	este es la suma de todas menos el de ella
	=> C(n) = T(n - 1) - C(n - 1)
 
	T(n) es la suma de todas las vacas despues de n pasos, como cada vaca
	suma todos los numeros de las otras entonces el total sera
	T(n) = T(n - 1) - C1(n - 1) + T(n - 1) - C2(n - 1) + ... + T(n - 1) - Cx(n - 1)
	donde C1 indica el numero de la vaca 1 despues de n pasos (asi las otras)
	T(n) = n * T(n - 1) - (C1(n - 1) + C2(n - 1) + ... + Cx(n - 1))
	T(n) = n * T(n - 1) - T(n - 1);
	T(n) = (n - 1) * T(n - 1)
	De aqui se pueden formar las recurrencias lineales
	C(n) = T(n - 1) - C(n - 1)
	T(n) = (n - 1) * T(n - 1)
 
	Poniendolo en forma de matrices
 
	[-1     1][C(n)] = [C(n + 1)]
	[ 0 n - 1][T(n)]   [T(n + 1)]
 
	de aqui que
						^ 1
	[-1     1]   [C(0)] = [C(n)]
	[ 0 n - 1]   [T(0)]   [T(n)]
 
	El como la matriz es la misma para todas las vacas solo hay
	calcular la matriz elevada a la n y para cada vaca calcular C(n)
	C(n) = M[0][0] * C(0) + M[0][1] * T(0)
*/
 

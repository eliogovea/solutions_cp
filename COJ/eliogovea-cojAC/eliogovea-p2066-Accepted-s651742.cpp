#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 10007;

int n, a[3];
vvi M;

vvi mult(vvi a, vvi b) {
	vvi r(3, vi(3, 0));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				r[i][j] = (r[i][j] + ((a[i][k] * b[k][j]) % mod)) % mod;
	return r;
}

vvi pow(vvi a, int n) {
	vvi r(3, vi(3, 0));
	for (int i = 0; i < 3; i++)
		r[i][i] = 1;
	while (n) {
		if (n & 1) r = mult(r, a);
		a = mult(a, a);
		n >>= 1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> a[0] >> a[1] >> a[2];

	M = vvi(3, vi(3, 0));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M[i][j] = (i != j) ? 3 : 0;

	M = pow(M, n);

	for (int i = 0; i < 3; i++) {
		int x = 0;
		for (int j = 0; j < 3; j++)
			x = (x + ((a[j] * M[i][j]) % mod)) % mod;
		cout << x;
		if (i != 2) cout << " ";
		else cout << "\n";
	}
}

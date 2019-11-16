#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

typedef long long LL;

const int mod = 1e9 + 7;

const int MAXN = 3000;

int tc, n, C[MAXN + 5][MAXN + 5];


int main() {//freopen("dat.in","r",stdin);
	for (int i = 0; i < MAXN; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 2; i < MAXN; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

	cin >> tc;
	while (tc--) {
		cin >> n;
		int i = 0;
		while (n > (1 << i)) {
			n -= (1 << i);
			i++;
		}
		i = 1 << i;
		cout << (C[i][n] - 1 + mod) % mod << "\n";
	}
}


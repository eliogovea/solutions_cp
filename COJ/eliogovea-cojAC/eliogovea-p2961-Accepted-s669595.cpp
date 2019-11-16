//============================================================================
// Name        : local.cpp
// Author      : Kino
// Version     :
// Copyright   : Another_sUrPRise
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

typedef long long LL;

LL f[25], c[25][25];

int main() {//freopen("dat.in","r",stdin);
	f[0] = 1;
	for (LL i = 1; i <= 20; i++)
		f[i] = i * f[i - 1];
	for (int i = 0; i <= 20; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i <= 20; i++)
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	LL n, p, a, b, tc;
	while (cin >> n && n) {
		cin >> p >> a >> b;
		LL d = 0;
		LL ans = 0;
		for (int i = 1; i <= p; i++) {
			if (i - 1 < a) continue;
			if (n - i < b) continue;
			ans += c[i - 1][a] * c[n - i][b];
		}
		for (int i = a + 1; i + b <= n; i++)
			d += c[i - 1][a] * c[n - i][b];
	LL g = __gcd(ans, d);
	ans /= g;
	d /= g;
	cout << ans << "/" << d << "\n";
	}
}


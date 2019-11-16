#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m, a, b;

int main() {//freopen("dat.in","r",stdin);
	while (cin >> n >> m) {
		a = (n * m * (n - 1ll) * (m - 1ll)) / 4ll;
		b = (m * n * (n - 1)) / 2ll + (n * m * (m - 1)) / 2ll;
		cout << "Triangles: " << b << "\n";
		cout << "Quadrilaterals: " << a << "\n\n";
	}
}

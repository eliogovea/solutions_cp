#include <bits/stdc++.h>

using namespace std;

int n, b, a;
int l, g;
map <int, int> M;

int main() {
	cin >> n >> b;
	bool ok = false;
	M[0] = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ok |= (a == b);
		l += (a < b);
		g += (a > b);
		if (ok) ans += M[g - l];
		if (a != b && !ok) M[g - l]++;
	}
	cout << ans << "\n";
}

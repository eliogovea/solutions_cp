#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL n, a[105], x;
LL gcd[105][105];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = 1LL;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> x; /// GCD(a[i], a[j]) = x;
			gcd[i][j] = gcd[j][i] = x;
			a[i] *= x / __gcd(x, a[i]);
			a[j] *= x  / __gcd(x, a[j]);
		}
	}

	for (int i = 2; i <= n; i++)
		if (a[i] <= a[i - 1]) {
			for (LL j = a[i - 1] / a[i] + 1; ; j++) {
				bool ok = true;
				for (int k = 1; k <= n; k++)
					if (i != k && __gcd(a[i] * j, a[k]) != gcd[i][k]) {
						ok = false;
						break;
					}
				if (ok) {
					a[i] *= j;
					break;
				}
			}
		}

	for (int i = 1; i <= n; i++) {
		cout << a[i];
		if (i != n) cout << " ";
		else cout << "\n";
	}
}

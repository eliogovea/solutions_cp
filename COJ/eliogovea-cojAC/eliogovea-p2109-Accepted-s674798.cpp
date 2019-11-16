#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL n, a[105], x;
bool criba[1000005];
vector<int> p;
LL gcd[105][105];

int main() {
	for (int i = 2; i <= 1000; i++)
		if (!criba[i])
			for (int j = i * i; j <= 1000000; j += i)
				criba[j] = true;
	p.push_back(2);
	for (int i = 3; i <= 1000000; i++)
		if (!criba[i]) p.push_back(i);
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
	int last = 0;
	for (int i = 2; i <= n; i++)
		if (a[i] <= a[i - 1]) {
			for (; last < (int)p.size(); last++) {
				if (a[i] * p[last] > a[i - 1]) {
					bool ok = true;
					for (int k = 1; k <= n; k++)
						if (k != i && __gcd(a[i] * p[last], a[k]) != gcd[i][k]) {
							ok = false;
							break;
						}
					if (ok) {
						a[i] *= p[last];
						last++;
						break;
					}
				}
			}

		}


	for (int i = 1; i <= n; i++) {
		cout << a[i];
		if (i != n) cout << " ";
		else cout << "\n";
	}
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int cp = 15;

int tc;
ll a, b, g;

ll solve(ll a, ll b) {
	int r = 0;
	for (int i = 0; i < cp; i++) {
		while (a % p[i] == 0) {
			r++;
			a /= p[i];
		}
		while (b % p[i] == 0) {
			r++;
			b /= p[i];
		}
	}
	if (a > 1 || b > 1) return -1;
	return r;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld%lld", &a, &b);
		g = __gcd(a, b);
		printf("%lld\n", solve(a / g, b / g));
	}
}

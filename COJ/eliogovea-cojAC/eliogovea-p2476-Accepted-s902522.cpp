#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

LL gcd(LL a, LL b) {
    if (!b) return a;
    return gcd(b, a % b);
}

LL val[1005];

inline LL calc(LL x) {
    //if (x <= 20) return val[x];
	if (x == 2) return 1ULL;
	if (x == 3) return 3ULL;
	LL cur = 6;
	LL res = 1 + (val[2] + 1ULL) * (x - x / 2ULL - 1ULL) + (val[3] + 1ULL) * (x / 2ULL - 1ULL - x / 6ULL);
	for (int i = 4; i <= 1000; i++) {
		LL next = cur / gcd(cur, (LL)i) * (LL)i;
		//cout << i << " " << cur << " " << next << "\n";
		res += (x / cur - x / next) * (val[i] + 1ULL);
		//cout << res << "\n";
		if (cur / gcd(cur, (LL)i) > x / (LL)i) break;
		cur = next;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    val[2] = 1;
    for (int i = 3; i <= 1000; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j) {
                val[i] = val[j] + 1;
                break;
            }
        }
    }
	LL a, b;
	cin >> a >> b;
	cout << calc(b) - calc(a - 1) << "\n";
}

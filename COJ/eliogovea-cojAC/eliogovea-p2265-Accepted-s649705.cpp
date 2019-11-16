#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 25;

ll n, a[MAXN], p, sum;

int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	bool sol = false;
	for (int i = 1; i < (1 << n); i++) {
		sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) sum += a[j];
		if (sum == p) {
			sol = true;
			break;
		}
	}
	if (sol) cout << "YES\n";
	else cout << "NO\n";
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000;

ll tc, n;

int main() {
    ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << 2ll + n * (n - 1ll) << '\n';
	}
}

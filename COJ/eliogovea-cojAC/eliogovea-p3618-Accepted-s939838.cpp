#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1000000000;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long p;
		cin >> p;
		if (p == 3LL) {
            cout << "12\n";
            continue;
		}
		cout << 2LL * ((p + 1LL) / 2LL + 1) << "\n";
	}

}

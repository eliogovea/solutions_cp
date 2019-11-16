#include <iostream>
#include <cstdio>

using namespace std;

int tc;
long long a;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> a;
		if (a & 1ll) cout << (a << 1ll) << '\n';
		else {
			while (!(a & 1ll)) a >>= 1ll;
			cout << a << '\n';
		}
	}
}

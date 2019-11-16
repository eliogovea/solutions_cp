#include <iostream>

using namespace std;

int tc, a[20], x, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		for (int i = 1; i <= 16; i++) {
			cin >> a[i];
			if (a[i] == 16) x = i;
		}
		for (;x + 4 <= 16; x += 4) swap(a[x], a[x + 4]);
		for (;x + 1 <= 16; x++) swap(a[x], a[x + 1]);
		ans = 0;
		for (int i = 2; i < 16; i++)
			for (int j = 1; j < i; j++)
				if (a[i] < a[j]) ans ^= 1;
		if (ans) cout << "no\n";
		else cout << "yes\n";
	}
}

#include <iostream>

using namespace std;

int tc;
string a, b;
int pi[200005];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		int sa = a.size();
		int sb = b.size();
		b += "#";
		b += a;
		int n = sa + sb + 1;
		ans = 0;
		for (int i = 1, x = sb + 1; i < n; i++) {  // KMP
			int j = pi[i - 1];
			while (j > 0 && b[i] != b[j]) {
				j = pi[j - 1];
			}
			if (b[i] == b[j]) {
				j++;
			}
			pi[i] = j;
			if (i >= sb + 1) {
				// voy a contar todas las substring validas que terminan en i
				if (pi[i] == sb) { // match
					x = i - sb + 1 + 1; // no pueden comenzar en una posicion menor que x porque habria match
				}
        ans += i - x + 1; // cuento todas las substr desde x hasta i
			}
		}
		cout << ans << "\n";
	}
}

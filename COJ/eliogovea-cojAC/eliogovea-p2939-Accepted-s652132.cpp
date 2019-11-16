#include <iostream>

using namespace std;

int tc, dig[100005];
string str;

int main() {
	cin >> tc;
	while (tc--) {
		str.clear();
		for (int i = 0; i < 100005; i++) dig[i] = 0;
		cin >> str;
		int lo = 0, hi = str.size();
		for (int i = 0; i < hi; i++) dig[i] = str[hi - 1 - i] - '0';
		int cero = 0, uno = 0;
		while (true) {
			if (lo == hi) break;
			int carry = 0, aux = dig[lo];
			for (int i = lo + 1; i < hi; i++) {
				carry += 5 * dig[i];
				dig[i] = carry % 10;
				carry /= 10;
			}
			while (carry) {
				dig[hi++] = carry % 10;
				carry /= 10;
			}
			if (dig[lo] & 1) uno = 1;
			else cero = 1;
			if (cero && uno) break;
			carry = dig[lo++] / 2;
			for (int i = lo; carry; carry /= 10) {
				carry += dig[i];
				dig[i] = carry % 10;
				if (i + 1 > hi) hi = i + 1;
			}
		}
		if (cero && uno) cout << "YES\n";
		else cout << "NO\n";
	}
}

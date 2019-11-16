#include <iostream>
//#include <fstream>

using namespace std;

int tc, a[10], tot, sum;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		bool sol = false;
		tot = 0;
		for (int i = 0; i < 6; i++) cin >> a[i], tot += a[i];
		for (int i = 0; i < (1 << 6) && !sol; i++) {
			sum = 0;
			for (int j = 0; j < 6; j++)
				if (i & (1 << j)) sum += a[j];
			if (2 * sum == tot) sol = true;
		}
		if (sol) cout << "Tobby puede cruzar\n";
		else cout << "Tobby no puede cruzar\n";
	}
}

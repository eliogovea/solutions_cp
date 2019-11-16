#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1000005;

int tc, pi[MAXN], cas, sol;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		sol = 0;
		cin >> b >> a;
		int len = a.size();
		a += '#';
		int i = 1, j = 0;
		for (; a[i]; i++) {
			while (j > 0 && a[i] != a[j]) j = pi[j - 1];
			if (a[i] == a[j]) j++;
			pi[i] = j;
		}
		for (i = 0; b[i]; i++) {
			while (j > 0 && b[i] != a[j]) j = pi[j - 1];
			if (b[i] == a[j]) j++;
			if (j == len) sol++;
		}
		cout << "Case " << ++cas << ": " << sol << "\n";
	}
}

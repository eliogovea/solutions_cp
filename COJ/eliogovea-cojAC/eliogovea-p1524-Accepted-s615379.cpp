#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int tc;
string str;
set<int> sol;

bool primo(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> str;
		int n = (int)str.size();
		sort(str.begin(), str.end());
		do {
			int num;
			for (int mask = 1; mask < (1 << n); mask++) {
				num = 0;
				for (int i = 0; i < n; i++)
					if (mask & (1 << i)) num = 10 * num + str[i] - '0';
				if (primo(num)) sol.insert(num);
			}
		} while (next_permutation(str.begin(), str.end()));
		cout << sol.size() << endl;
		if (tc) sol.clear();
	}
}

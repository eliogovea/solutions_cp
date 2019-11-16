#include <iostream>
#include <map>

using namespace std;

map <int, bool> memo;

bool win(int cur, long long lim) {
	if (cur >= lim) {
		return false;
	}
	if (memo.find(cur) != memo.end()) {
		return memo[cur];
	}
	for (int i = 2; i <= 9; i++) {
		if (!win(cur * i, lim)) {
			memo[cur] = true;
			return true;
		}
	}
	memo[cur] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
        int n;
        cin >> n;
        memo.clear();
		cout << ((win(1, n) | (n == 1)) ? "Stan" : "Ollie") << " wins\n";
	}
}

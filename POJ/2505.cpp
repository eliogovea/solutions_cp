#include <iostream>
#include <map>

using namespace std;

map <long long, bool> memo;

bool win(long long cur, long long lim) {
	if (cur >= lim) {
		return false;
	}
	if (memo.find(cur) != memo.end()) {
		return memo[cur];
	}
	for (long long i = 2; i <= 9; i++) {
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

	long long n;
	while (cin >> n) {
		memo.clear();
		cout << (win(1, n) ? "Stan" : "Ollie") << " wins.\n";
	}
}

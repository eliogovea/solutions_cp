#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> digits;

void fill(vector <int> &d, int n) {
	while (n) {
		d.push_back(n % 10);
		n /= 10;
	}
}

bool dfs(int n, int cur, int last, int pos, bool cut) {
    //cout << n << " " << cur << " " << last << " " << pos << "\n";
	if (pos == digits.size()) {
        if (!cut) return false;
		if (n == cur * last) {
			return true;
		}
		return false;
	}
	if ((last != 0 && ((n / cur) % last == 0)) && digits[pos] != 0) {
		if (dfs(n, cur * last, 0, pos, true)) {
			return true;
		}
	}
	if (dfs(n, cur, 10 * last + digits[pos], pos + 1, cut)) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fill(digits, n);
	sort(digits.begin(), digits.end());
	bool ok = false;
	do {
		if (dfs(n, 1, 0, 0, false)) {
			ok = true;
			break;
		}
	} while (next_permutation(digits.begin(), digits.end()));
	cout << (ok ? "YES" : "NO") << "\n";
}

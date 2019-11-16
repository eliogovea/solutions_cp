#include <bits/stdc++.h>

using namespace std;

bool readLine(long long &n, vector <int> &c) {
	string line;
	if (!getline(cin, line)) {
		return false;
	}
	istringstream in(line);
	in >> n;
	c.clear();
	int x;
	while (in >> x) {
		c.push_back(x);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int MOD = 10;
	const int cycleSize = 60;
	vector <int> values(cycleSize);
	values[0] = 1;
	values[1] = 1;
	for (int i = 2; i < cycleSize; i++) {
		values[i] = (values[i - 2] + values[i - 1]) % MOD;
	}
	long long n;
	vector <int> c;
	while (readLine(n, c)) {
		int k = c.size();
		if (n < k) {
			cout << "0\n";
			continue;
		}
		long long answer = 0;
		for (int start = 0; start < cycleSize && start < n; start++) {
			bool ok = true;
			for (int i = 0; i < k; i++) {
				if (values[(start + i) % cycleSize] != c[i]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
                continue;
			}
			if (n - k - start < 0) {
				continue;
			}
			long long x = (long long)(n - k - start) / (long long)cycleSize + 1;
			answer += x;
		}
		cout << answer << "\n";
	}
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	long long n;
	cin >> n;
	n--;

	int l = s.length();

	long long curLength = l;
	while (curLength < n + 1) {
		curLength *= 2LL;
	}

	while (curLength > l) {
		if (n >= curLength / 2LL) {
			n = (n - 1 + (curLength / 2LL)) % (curLength / 2LL);
		}
		curLength /= 2LL;
	}

	cout << s[n] << "\n";
}
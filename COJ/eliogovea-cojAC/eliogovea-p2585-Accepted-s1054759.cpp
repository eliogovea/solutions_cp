#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	bool ok = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			ok = true;
			break;
		}
	}

	if (!ok) {
		cout << "Rabbit\n";
	} else {
		int xorSum = 0;
		int cnt = 0;
		s += "#";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '#') {
				xorSum ^= cnt;
				cnt = 0;
			} else {
				cnt++;
			}
		}
		cout << ((xorSum != 0) ? "Cat" : "Rabbit") << "\n";
	}
}

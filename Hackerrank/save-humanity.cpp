#include <bits/stdc++.h>

using namespace std;

template <class T>
vector <int> zFunction(const T & s, int n) {
	int l = 0, r = 0;
	vector <int> z(n);
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string t, s;
		cin >> t >> s;

		auto z = zFunction(s + "#" + t, s.size() + 1 + t.size());
		z.erase(z.begin(), z.begin() + s.size() + 1);
		
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());

		auto zr = zFunction(s + "#" + t, s.size() + 1 + t.size());
		zr.erase(zr.begin(), zr.begin() + s.size() + 1);
		reverse(zr.begin(), zr.end());

		vector <int> answer;

		for (int i = 0; i + (int)s.size() - 1 < (int)t.size(); i++) {
			if (z[i] + zr[i + (int)s.size() - 1] >= (int)s.size() - 1) {
				answer.push_back(i);
			}
		}

		if (answer.size() == 0) {
			cout << "No Match!\n";
		} else {
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i];
				if (i + 1 < answer.size()) {
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
}

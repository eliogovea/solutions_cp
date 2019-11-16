#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

string a, b;

int pi[N];

vector <int> match;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	for (int i = 1, j = 0; i < b.size(); i++) {
		while (j > 0 && b[i] != b[j]) j = pi[j - 1];
		if (b[i] == b[j]) j++;
		pi[i] = j;
	}
	b += "#";
	for (int i = 0, j = 0; i < a.size(); i++) {
		while (j > 0 && a[i] != b[j]) j = pi[j - 1];
		if (a[i] == b[j]) j++;
		if (j == b.size() - 1) {
			match.push_back(i - b.size());
		}
	}
	if (match.size() == 0) {
		cout << "0\n";
		return 0;
	}
	int ans = 1;
	int r = match[0] + b.size() - 1 - 1;
	for (int i = 1; i < match.size(); i++) {
		if (match[i] > r) {
			ans++;
			r = match[i] + b.size() - 1 - 1;
		}
	}
	cout << ans << "\n";
}

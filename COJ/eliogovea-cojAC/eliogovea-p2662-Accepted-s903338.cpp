#include <bits/stdc++.h>

using namespace std;

struct item {
	string s[3];
	void get() {
		cin >> s[0] >> s[1] >> s[2];
		sort(s, s + 3);
	}
};

bool operator < (const item &a, const item &b) {
	for (int i = 0; i < 3; i++) {
		if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
	}
	return false;
}

map <item, int> M;
map <item, int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	item x;
	cin >> n;
	while (n--) {
		x.get();
		M[x]++;
	}
	int ans = 0;
	for (it = M.begin(); it != M.end(); it++) {
		ans = max(ans, it->second);
	}
	cout << ans << "\n";
}

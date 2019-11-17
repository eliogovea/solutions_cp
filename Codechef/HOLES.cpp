#include <bits/stdc++.h>

using namespace std;

const string s[] = {
	"",
	"ADOPQR",
	"B"
};

int n;
string line;

int cnt[300];

int main() {
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; s[i][j]; j++) {
			cnt[s[i][j]] = i;
		}
	}
	cin >> n;
	while (n--) {
		cin >> line;
		int ans = 0;
		for (int i = 0; line[i]; i++) {
			ans += cnt[line[i]];
		}
		cout << ans << "\n";
	}
}


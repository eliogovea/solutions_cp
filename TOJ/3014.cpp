#include <iostream>

using namespace std;

int n;
string s, ss;
int cnt[1000], tot, ans;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	while (true) {
		getline(cin, s);
		n = 0;
		for (int i = 0; i < s.size(); i++) {
			n = 10 * n + s[i] - '0';
		}
		if (n == 0) {
			break;
		}
		getline(cin, s);
		ans = tot = 0;
		for (int i = 0; i < 256; i++) {
			cnt[i] = 0;
		}
		for (int i = 0, j = 0; i < s.size(); i++) {
			if (cnt[s[i]] == 0) {
				tot++;
			}
			cnt[s[i]]++;
			while (tot > n) {
				if (cnt[s[j]] == 1) {
					tot--;
				}
				cnt[s[j]]--;
				j++;
			}
			if (tot <= n && ans < i - j + 1) {
				ans = i - j + 1;
			}
		}
		cout << ans << "\n";
	}
}


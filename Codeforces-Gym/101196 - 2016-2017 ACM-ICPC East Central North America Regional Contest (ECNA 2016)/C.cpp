// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196C

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	string s, k;
	cin >> s >> k;
	int n = s.size();
	string ans;
	for (int i = 0; i < n; i++) {
		char x = 'A' + (((s[i] - 'A') - (k[i] - 'A') + 26) % 26);
		ans += x;
		k += x;
	}
	cout << ans << "\n";
}

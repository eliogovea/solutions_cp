// Problem: pace=1&num=1083
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//froepen("dat.txt", "r", stdin);
	cin >> n >> s;
	k = s.size();
	int res = 1;
	while (n > 0) {
		res = res * n;
		n -= k;
	}
	cout << res << "\n";
}

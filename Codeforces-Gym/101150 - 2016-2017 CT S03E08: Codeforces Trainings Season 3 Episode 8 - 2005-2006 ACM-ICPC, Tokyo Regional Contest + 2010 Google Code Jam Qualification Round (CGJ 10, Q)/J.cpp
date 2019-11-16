// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150J

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		cout << (((k & ((1LL << n) - 1LL)) == ((1LL << n) - 1LL)) ? "ON" : "OFF") << "\n";
	}
}

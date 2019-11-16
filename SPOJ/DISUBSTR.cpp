#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
const ull B = 257;
const ull C = 1231;
 
const int N = 1005;
 
ull hash[N];
ull POW[N];
 
ull get(int s, int e) {
	return hash[e] - hash[s] * POW[e - s];
}
 
string s;
 
int lcp(int a, int b) {
	int lo = 0;
	int hi = s.size() - max(a, b);
	int res = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (get(a, a + mid) == get(b, b + mid)) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return res;
}
 
bool comp(const int &a, const int &b) {
	int l = lcp(a, b);
	return s[a + l] < s[b + l];
}
 
int SA[N];
 
int t;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	POW[0] = 1;
	for (int i = 1; i < N; i++) {
		POW[i] = POW[i - 1] * B;
	}
	cin >> t;
	while (t--) {
		cin >> s;
		hash[0] = C;
		for (int i = 1; i <= s.size(); i++) {
			hash[i] = hash[i - 1] * B + s[i - 1];
			SA[i - 1] = i - 1;
		}
		stable_sort(SA, SA + s.size(), comp);
		int ans = (s.size() * (s.size() + 1)) / 2;
		for (int i = 0; i + 1 < s.size(); i++) {
			ans -= lcp(SA[i], SA[i + 1]);
		}
		cout << ans << "\n";
	}
}
 

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>

using namespace std;

int n, a[1005], mx;
vector<pair<int, int> > S[1005], sol;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		a[0] = a[n + 1] = a[i];
		int lo = i - 1;
		int hi = i + 1;
		while (a[lo] % a[i]) lo--;
		while (a[hi] % a[i]) hi++;
		lo++; hi--;
		if (hi - lo + 1 < mx) continue;
		if (hi - lo + 1 > mx) mx = hi - lo + 1;
		S[mx].push_back(make_pair(lo, hi));
	}
	sort(S[mx].begin(), S[mx].end());
	int last = -1;
	for (int i = 0; i < S[mx].size(); i++) {
    if (S[mx][i].first == last) continue;
    last = S[mx][i].first;
    sol.push_back(S[mx][i]);
	}
	cout << mx << " " << sol.size() << "\n";
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i].first << " " << sol[i].second << "\n";
}

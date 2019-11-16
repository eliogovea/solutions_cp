#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, q, d, x, r, t, sol;
int pl[100005];
map<string, int> M;
map<string, int>::iterator it;
string s;
int main() {
  ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s >> d;
		M[s] = d;
		pl[i] = d;
	}
	sort(pl, pl + n);
	while (q--) {
		cin >> s >> d;
		x = d / 100, r = d % 100, t = 1 << x;
		t = t + r * t / 100;
		it = M.find(s);
		if (it == M.end() || it->second > t) {
			sol = upper_bound(pl, pl + n, t) - pl;
			cout << "No " << sol << '\n';
		}
		else cout << "Yes\n";
  }
}

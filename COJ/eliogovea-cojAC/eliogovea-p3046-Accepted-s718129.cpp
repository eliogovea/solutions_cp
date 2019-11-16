#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int n;
vector<int> a, b, da, db, v, pi;

void fd(vector<int> &x, vector<int> &dx) {
	dx.clear();
	sort(x.begin(), x.end());
	dx.push_back(360000 - (x[n - 1] - x[0]));
	for (int i = 1; i < n; i++)
		dx.push_back(x[i] - x[i - 1]);
}

int main() {
  //freopen("dat.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	fd(a, da);
	fd(b, db);
	for (int i = 0; i < n; i++) v.push_back(da[i]);
	v.push_back(-1);
	for (int i = 0; i < n; i++) v.push_back(db[i]);
	for (int i = 0; i < n; i++) v.push_back(db[i]);
	int sv = v.size();
	pi.resize(sv + 5);
	bool ok = false;
	for (int i = 1; i < sv; i++) {
		int j = pi[i - 1];
		while (j > 0 && v[i] != v[j]) j = pi[j - 1];
		if (v[i] == v[j]) j++;
		pi[i] = j;
		if (j == n) {
			ok = true;
			break;
		}
	}
	if (ok) cout << "possible\n";
	else cout << "impossible\n";
}

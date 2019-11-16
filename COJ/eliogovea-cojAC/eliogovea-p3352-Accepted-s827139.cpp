#include <bits/stdc++.h>

using namespace std;

string t, p;

int pi[1000005];

vector<int> ini, fin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> p;
	int st = t.size();
	int sp = p.size();
	for (int i = 1; i < sp; i++) {
		int prev = pi[i - 1];
		while (prev > 0 && p[i] != p[prev]) {
			prev = pi[prev - 1];
		}
		if (p[i] == p[prev]) {
			prev++;
		}
		pi[i] = prev;
	}
	int cur = 0;
	for (int i = 0; i < st; i++) {
		while (cur > 0 && t[i] != p[cur]) {
			cur = pi[cur - 1];
		}
		if (t[i] == p[cur]) {
			cur++;
		}
		if (cur == sp) {
			ini.push_back(i - sp + 1);
		}
	}
	int last = -1;
	int pos = 0;
	int ans = 0;
	for (int i = 0; i < ini.size(); i++) {
		if (ini[i] < pos) {
			continue;
		}
		if (last == -1) {
			last = i;
		}
		if (i == ini.size() - 1 || ini[i + 1] > ini[last] + sp - 1) {
			ans++;
			pos = ini[i] + sp;
			last = -1;
		}
	}
	cout << ans << "\n";
}

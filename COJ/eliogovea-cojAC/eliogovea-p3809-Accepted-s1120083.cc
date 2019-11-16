#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100 * 1000 + 2;
const int ALPH = 26;
struct trie {
	int size;
	int root;
	int go[SIZE][ALPH];
	trie() {
		init();
	}
	inline int getNew() {
		fill(go[size], go[size] + ALPH, -1);
		return size++;
	}
	void init() {
		size = 0;
		root = getNew();
	}
	int add(const string &s) {
		int cur = root;
		for (int i = 0; i < (int)s.size(); i++) {
			if (go[cur][s[i] - 'a'] == -1) {
				go[cur][s[i] - 'a'] = getNew();
			}
			cur = go[cur][s[i] - 'a'];
		}
		return cur;
	}
} pref, suff;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, l;
	while (cin >> n >> q >> l) {
		pref.init();
		suff.init();
		vector <int> prefPos(l), suffPos(l);
		map <pair <int, int>, int> m;
		while (n--) {
			string s;
			cin >> s;
			{
				int cur = pref.root;
				for (int i = 0; i < l; i++) {
					if (pref.go[cur][s[i] - 'a'] == -1) {
						pref.go[cur][s[i] - 'a'] = pref.getNew();
					}
					prefPos[i] = cur = pref.go[cur][s[i] - 'a'];
				}
			}
			{
				int cur = suff.root;
				for (int i = l - 1; i >= 0; i--) {
					if (suff.go[cur][s[i] - 'a'] == -1) {
						suff.go[cur][s[i] - 'a'] = suff.getNew();
					}
					suffPos[i] = cur = suff.go[cur][s[i] - 'a'];
				}
			}
			for (int i = 0; i < l; i++) {
				m[make_pair((i == 0) ? 0 : prefPos[i - 1], (i == l - 1) ? 0 : suffPos[i + 1])]++;
			}
		}
		while (q--) {
			string s;
			cin >> s;
			{
				fill(prefPos.begin(), prefPos.end(), -1);
				int cur = pref.root;
				for (int i = 0; i < l; i++) {
					if (pref.go[cur][s[i] - 'a'] == -1) {
						break;
					}
					prefPos[i] = cur = pref.go[cur][s[i] - 'a'];
				}
			}
			{
				int cur = suff.root;
				fill(suffPos.begin(), suffPos.end(), -1);
				for (int i = l - 1; i >= 0; i--) {
					if (suff.go[cur][s[i] - 'a'] == -1) {
						break;
					}
					suffPos[i] = cur = suff.go[cur][s[i] - 'a'];
				}
			}
			int ans = 0;
			for (int i = 0; i < l; i++) {
				if (m.find(make_pair((i == 0) ? 0 : prefPos[i - 1], (i == l - 1) ? 0 : suffPos[i + 1])) != m.end()) {
					ans += m[make_pair((i == 0) ? 0 : prefPos[i - 1], (i == l - 1) ? 0 : suffPos[i + 1])];
				}
			}
			cout << ans << "\n";
		}
	}
}

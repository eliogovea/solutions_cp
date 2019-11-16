#include <bits/stdc++.h>

using namespace std;

const int MAXS = 100005;

int length[MAXS];
map <int, int> next[MAXS];
int suffixLink[MAXS];

int last;
int size;

int getNew(int _length) {
	int now = size;
	size++;
	length[now] = _length;
	next[now] = map <int, int> ();
	suffixLink[now] = -1;
	return now;
}

int getClone(int from, int _length) {
	int now = size;
	size++;
	length[now] = _length;
	next[now] = next[from];
	suffixLink[now] = suffixLink[from];
	return now;
}

void init() {
	size = 0;
	last = getNew(0);
}

void add(int c) {
	int p = last;
	int cur = getNew(length[p] + 1);
	while (p != -1 && next[p].find(c) == next[p].end()) {
		next[p][c] = cur;
		p = suffixLink[p];
	}
	if (p == -1) {
		suffixLink[cur] = 0;
	} else {
		int q = next[p][c];
		if (length[p] + 1 == length[q]) {
			suffixLink[cur] = q;
		} else {
			int clone = getClone(q, length[p] + 1);
			suffixLink[q] = clone;
			suffixLink[cur] = clone;
			while (p != -1 && next[p][c] == q) {
				next[p][c] = clone;
				p = suffixLink[p];
			}
		}
	}
	last = cur;
}

int cnt[MAXS];

int freq[MAXS];
int order[MAXS];

int from[MAXS];
char let[MAXS];

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i <= 2 * s.size(); i++) {
		cnt[i] = 0;
	}
	init();
	for (int i = 0; i < s.size(); i++) {
		add(s[i]);
		cnt[last]++;
	}
	int maxLength = 0;
	for (int i = 0; i < size; i++) {
		maxLength = max(maxLength, length[i]);
	}
	for (int i = 0; i <= maxLength; i++) {
		freq[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		freq[length[i]]++;
	}
	for (int i = 1; i <= maxLength; i++) {
		freq[i] += freq[i - 1];
	}
	for (int i = 0; i < size; i++) {
		order[--freq[length[i]]] = i;
	}
	for (int i = size - 1; i > 0; i--) {
		int s = order[i];
		cnt[suffixLink[s]] += cnt[s];
	}
	for (int i = 0; i < size; i++) {
		int s = order[i];
		for (map <int, int> :: iterator it = next[s].begin(); it != next[s].end(); it++) {
			int x = it->second;
			char c = it->first;
			if (length[s] + 1 == length[x]) {
				from[x] = s;
				let[x] = c;
			}
		}
	}
	long long best = 0;
	for (int s = 0; s < size; s++) {
		if (cnt[s] >= 2) {
			best = max(best, (long long)cnt[s] * length[s]);
		}
	}
	if (best == 0) {
		cout << "0\n";
	} else {
		string ans = "";
		for (int s = 0; s < size; s++) {
			if (cnt[s] >= 2) {
				long long val = (long long)cnt[s] * length[s];
				if (val == best) {
					while (s != 0) {
						ans += let[s];
						s = from[s];
					}
					reverse(ans.begin(), ans.end());
					break;
				}
			}
		}
		cout << best << "\n" << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

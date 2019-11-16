#include <bits/stdc++.h>

using namespace std;

const int MAXS = 2 * 100000 + 1;

int length[MAXS + 1];
map <char, int> next[MAXS + 1];
int suffixLink[MAXS + 1];

int size;
int last;

int getNew(int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = map <char, int> ();
	suffixLink[now] = -1;
	return now;
}

int getClone(int from, int _length) {
	int now = size++;
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

int freq[MAXS];
int order[MAXS];

void getOrder() {
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
}

long long cnt[MAXS];

string s;

void solve() {
	while (cin >> s) {
		if (s == "*") {
			break;
		}
		for (int i = 0; i < size; i++) {
			cnt[i] = 0;
		}
		init();
		for (int i = 0; i < s.size(); i++) {
			add(s[i]);
			cnt[last]++;
		}
		getOrder();
		for (int i = size - 1; i > 0; i--) {
			int s = order[i];
			cnt[suffixLink[s]] += cnt[s];
		}
		int ans = 0;
		for (int i = 1; i < size; i++) {
			if (cnt[i] >= 2) {
				ans += length[i] - length[suffixLink[i]];
			}
		}
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

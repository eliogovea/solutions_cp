#include <bits/stdc++.h>

using namespace std;

const int MAXS = 2 * 500000 + 1;

int length[MAXS];
map <char, int> next[MAXS];
int suffixLink[MAXS];

int size;
int last;

inline int getNew(int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = map <char, int> ();
	suffixLink[now] = -1;
	return now;
}

inline int getClone(int node, int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = next[node];
	suffixLink[now] = suffixLink[node];
	return now;
}

void init() {
	size = 0;
	last = getNew(0);
}

void add(char c) {
	int p = last;
	if (next[p].find(c) != next[p].end()) {
		int q = next[p][c];
		if (length[p] + 1 == length[q]) {
			last = q;
		} else {
			int clone = getClone(q, length[p] + 1);
			suffixLink[q] = clone;
			while (p != -1 && next[p][c] == q) {
				next[p][c] = clone;
				p = suffixLink[p];
			}
			last = clone;
		}
	} else {
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

int n;
string s;
long long v;
long long sum[MAXS];

void solve() {
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		cin >> s >> v;
		for (int j = 0; j < s.size(); j++) {
			add(s[j]);
			sum[last] += v;
		}
		last = 0;
	}
	getOrder();
	for (int i = size - 1; i >= 0; i--) {
		int s = order[i];
		sum[suffixLink[s]] += sum[s];
	}
	long long ans = 0;
	for (int i = 1; i < size; i++) {
		ans = max(ans, (long long)length[i] * sum[i]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

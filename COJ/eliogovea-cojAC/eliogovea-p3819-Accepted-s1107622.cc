#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int L = 100;
const int SIZE = 2 * N * L + 2;

int length[SIZE];
map <char, int> go[SIZE];
int suffixLink[SIZE];

int size;
int last;

inline int getNew(int _length) {
	int now = size++;
	length[now] = _length;
	go[now] = map <char, int> ();
	suffixLink[now] = -1;
	return now;
}

inline int getClone(int node, int _length) {
	int now = size++;
	length[now] = _length;
	go[now] = go[node];
	suffixLink[now] = suffixLink[node];
	return now;
}

void init() {
	size = 0;
	last = getNew(0);
}

void add(char c) {
	int p = last;
	if (go[p].find(c) != go[p].end()) {
		int q = go[p][c];
		if (length[p] + 1 == length[q]) {
			last = q;
		} else {
			int clone = getClone(q, length[p] + 1);
			suffixLink[q] = clone;
			while (p != -1 && go[p][c] == q) {
				go[p][c] = clone;
				p = suffixLink[p];
			}
			last = clone;
		}
	} else {
		int cur = getNew(length[p] + 1);
		while (p != -1 && go[p].find(c) == go[p].end()) {
			go[p][c] = cur;
			p = suffixLink[p];
		}
		if (p == -1) {
			suffixLink[cur] = 0;
		} else {
			int q = go[p][c];
			if (length[p] + 1 == length[q]) {
				suffixLink[cur] = q;
			} else {
				int clone = getClone(q, length[p] + 1);
				suffixLink[q] = clone;
				suffixLink[cur] = clone;
				while (p != -1 && go[p][c] == q) {
					go[p][c] = clone;
					p = suffixLink[p];
				}
			}
		}
		last = cur;
	}
}

int freq[SIZE];
int order[SIZE];

int n;
string s;

map <long long, int> pos;

const int BITS = 60;

long long used[(N + BITS - 1) / BITS][SIZE];

int ans[N + 10];

void solve() {
	for (int i = 0; i < BITS; i++) {
		pos[(1LL << i)] = i;
	}
	cin >> n;
	int lb = (n - 1) / BITS;
	init();
	for (int i = 0; i < n; i++) {
		cin >> s;
		ans[i] = (int)s.size();
		for (int j = 0; j < s.size(); j++) {
			add(s[j]);
			used[i / BITS][last] |= (1LL << (i % BITS));
		}
		last = 0;
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
		int cnt = 0;
		int id = -1;
		for (int b = 0; b <= lb; b++) {
			used[b][suffixLink[s]] |= used[b][s];
			if (used[b][s]) {
				cnt++;
				id = b;
			}
		}
		if (cnt == 1 && pos.find(used[id][s]) != pos.end()) {
			id = BITS * id + pos[used[id][s]];
			ans[id] = min(ans[id], length[suffixLink[s]] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}

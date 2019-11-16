#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000;
const int MAXS = 2 * MAXN + 5;

int length[MAXS];
map <int, int> next[MAXS];
int suffixLink[MAXS];

int size;
int last;

int createNew(int _length) {
	int now = size;
	size++;
	length[now] = _length;
	next[now] = map <int, int> ();
	suffixLink[now] = -1;
	return now;
}

int createClone(int from, int _length) {
	int now = size;
	size++;
	length[now] = _length;
	next[now] = next[from];
	suffixLink[now] = suffixLink[from];
	return now;
}

void init() {
	size = 0;
	last = createNew(0);
}

void add(int c) {
	int p = last;
	int cur = createNew(length[p] + 1);
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
			int clone = createClone(q, length[p] + 1);
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

int n, k;
int a[MAXN + 5];
map <int, int> M;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (M.find(a[i]) != M.end()) {
			a[i] = M[a[i]];
		} else {
			int id = M.size();
			M[a[i]] = id;
			a[i] = id;
		}
	}
	init();
	for (int i = 0; i < n; i++) {
		add(a[i]);
		cnt[last]++;
	}
	int maxLength = 0;
	for (int s = 0; s < size; s++) {
		maxLength = max(maxLength, length[s]);
	}
	for (int i = 0; i <= maxLength; i++) {
		freq[i] = 0;
	}
	for (int s = 0; s < size; s++) {
		freq[length[s]]++;
	}
	for (int i = 1; i <= maxLength; i++) {
		freq[i] += freq[i - 1];
	}
	for (int s = 0; s < size; s++) {
		order[--freq[length[s]]] = s;
	}
	for (int i = size - 1; i > 0; i--) {
		int s = order[i];
		cnt[suffixLink[s]] += cnt[s];
	}
	int ans = 0;
	for (int s = 0; s < size; s++) {
		if (cnt[s] >= k) {
			ans = max(ans, length[s]);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input3155.txt", "r", stdin);
	solve();
}

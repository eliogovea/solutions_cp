// Problem: pace=1&num=1517
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int MAXS = 2 * 2 * 100000 + 5;
const int ALPH = 26;

int length[MAXS];
int next[MAXS][ALPH];
int suffixLink[MAXS];

int size;
int last;

int createNewNode(int _length) {
    int now = size;
    size++;
	length[now] = _length;
	for (int c = 0; c < ALPH; c++) {
		next[now][c] = -1;
	}
	suffixLink[now] = -1;
	return now;
}

int createClone(int from, int _length) {
	int now = size;
	size++;
	length[now] = _length;
	for (int c = 0; c < ALPH; c++) {
		next[now][c] = next[from][c];
	}
	suffixLink[now] = suffixLink[from];
	return now;
}


void init() {
	size = 0;
	last = createNewNode(0);
}

void add(int c) {
	int p = last;
	if (next[p][c] != -1) {
		int q = next[p][c];
		if (length[p] + 1 == length[q]) {
			last = q;
		} else {
			int clone = createClone(q, length[p] + 1);
			suffixLink[q] = clone;
			while (p != -1 && next[p][c] == q) {
				next[p][c] = clone;
				p = suffixLink[p];
			}
			last = clone;
		}
	} else {
		int cur = createNewNode(length[p] + 1);
		while (p != -1 && next[p][c] == -1) {
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
}

bool used[3][MAXS];

int cnt[MAXS];
int order[MAXS];
int from[MAXS];
char let[MAXS];

string LCS(string a, string b) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 * (a.size() + b.size()) + 1; j++) {
			used[i][j] = false;
		}
	}
	init();
	for (int i = 0; i < a.size(); i++) {
		add(a[i] - 'A');
		used[0][last] = true;
	}
	last = 0;
	for (int i = 0; i < b.size(); i++) {
		add(b[i] - 'A');
		used[1][last] = true;
	}
	int maxLength = 0;
	for (int i = 1; i < size; i++) {
		maxLength = max(maxLength, length[i]);
	}
	/// counting sort
	for (int i = 0; i <= maxLength; i++) {
        cnt[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		cnt[length[i]]++;
	}
	for (int i = 1; i <= maxLength; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < size; i++) {
		order[--cnt[length[i]]] = i;
	}
	for (int i = size - 1; i > 0; i--) {
		int s = order[i];
		for (int j = 0; j < 2; j++) {
			if (used[j][s]) {
				used[j][suffixLink[s]] = true;
			}
		}
	}
	from[0] = -1;
	for (int s = 0; s < size; s++) {
		for (int c = 0; c < ALPH; c++) {
			if (next[s][c] != -1) {
				if (length[s] + 1 == length[next[s][c]]) {
					from[next[s][c]] = s;
					let[next[s][c]] = 'A' + c;
				}
			}
		}
	}
	int ansLength = 0;
	for (int s = 0; s < size; s++) {
		if (used[0][s] && used[1][s]) {
			ansLength = max(ansLength, length[s]);
		}
	}
	string ans;
	for (int s = 0; s < size; s++) {
		if (length[s] == ansLength && used[0][s] && used[1][s]) {
			string tmp;
			int now = s;
			while (now != 0) {
				tmp += let[now];
				now = from[now];
			}
			reverse(tmp.begin(), tmp.end());
			if (ans == "" || tmp < ans) {
                ans = tmp;
            }
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string a, b;

	cin >> n >> a >> b;
	cout << LCS(a, b) << "\n";
}

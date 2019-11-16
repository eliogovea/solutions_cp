// 3867 - C1 - Binary Words

#include <bits/stdc++.h>

using namespace std;

const int ALPH = 2;
const int SIZE = 40 * 20 + 10;

struct trie {
	int go[SIZE][ALPH];
	bool end[SIZE];
	int size;
	trie() {
		init();
	}
	void init() {
		size = 0;
		getNew();
	}
	int getNew() {
		for (char c = 0; c < ALPH; c++) {
			go[size][c] = -1;
		}
		end[size] = false;
		return size++;
	}
	int add(const string &s) {
		int n = s.size();
		int now = 0;
		for (int i = 0; i < n; i++) {
			char c = s[i] - '0';
			if (go[now][c] == -1) {
				go[now][c] = getNew();
			}
			now = go[now][c];
		}
		end[now] = true;
		return now;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n1, n2;
	cin >> n1 >> n2;
	trie t1, t2;
	string s;
	for (int i = 0; i < n1; i++) {
		cin >> s;
		t1.add(s);
	}
	for (int i = 0; i < n2; i++) {
		cin >> s;
		t2.add(s);
	}

	queue <pair <int, int> > Q;
	vector <vector <bool> > visited(t1.size, vector <bool> (t2.size));
	visited[0][0] = true;
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		int p1 = Q.front().first;
		int p2 = Q.front().second;
		Q.pop();
		if (t1.end[p1] && t2.end[p2]) {
			cout << "S\n";
			return 0;
		}
		if (t1.end[p1]) {
			if (!visited[0][p2]) {
				visited[0][p2] = true;
				Q.push(make_pair(0, p2));
			}
		}
		if (t2.end[p2]) {
			if (!visited[p1][0]) {
				visited[p1][0] = true;
				Q.push(make_pair(p1, 0));
			}
		}
		for (int c = 0; c < ALPH; c++) {
			if (t1.go[p1][c] != -1 && t2.go[p2][c] != -1) {
				if (!visited[t1.go[p1][c]][t2.go[p2][c]]) {
					visited[t1.go[p1][c]][t2.go[p2][c]] = true;
					Q.push(make_pair(t1.go[p1][c],t2.go[p2][c]));
				}
			}
		}
	}
	cout << "N\n";
	return 0;
}

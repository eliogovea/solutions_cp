#include <iostream>
#include <set>
#include <fstream>

using namespace std;

const int MAXN = 300005;

struct node {
	bool fin;
	int next[27];
} T[MAXN];

int sz;

void add(const string &s) {
	int v = 0, c;
	for (int i = 0; s[i]; i++) {
		c = s[i] - 'A';
		if (!T[v].next[c]) T[v].next[c] = ++sz;
		v = T[v].next[c];
	}
	T[v].fin = true;
}

set<string> S;

const int di[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

char mat[7][7];
bool mark[7][7];

void find(int v, int i, int j, string str) {
	if (i < 0 || i > 4 || j < 0 || j > 4) return;
	if (mark[i][j]) return;
	int c = mat[i][j] - 'A';
	int p = T[v].next[c];
	if (p == 0) return;
	mark[i][j] = true;
	if (T[p].fin) S.insert(str + mat[i][j]);
	for (int r = 0; r < 8; r++)
		find(p, i + di[r], j + dj[r], str + mat[i][j]);
	mark[i][j] = false;
}

int w;
string ss;

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
      cin >> ss;
      mat[i][j] = ss[0];
		}
	}
	cin >> w;
	while (w--) {
		cin >> ss;
		add(ss);
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			find(0, i, j, "");
	cout << S.size() << '\n';
}

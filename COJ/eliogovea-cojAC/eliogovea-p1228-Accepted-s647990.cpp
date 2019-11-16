#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAXN = 200005, alph = 26;

struct vertex {
	int fin;
	int next[alph];
	vertex() {
		fin = -1;
		for (int i = 0; i < alph; i++) next[i] = -1;
	}
} T[MAXN];

int n, states = 1;

vector<string> words;
string str;

void add(int p) {
	const string &s = words[p];
	int v = 0;
	for (int i = 0; s[i]; i++) {
		char c = s[i] - 'a';
		if (T[v].next[c] == -1)
			T[v].next[c] = states++;
		v = T[v].next[c];
	}
	T[v].fin = p;
}

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	while (cin >> str) {
		words.push_back(str);
		add(n++);
	}
	for (int i = 0; i < n; i++) {
		int v1 = 0;
		bool comp = false;
		const string &s = words[i];
		for (int j = 0; s[j + 1] && !comp; j++) {
			char c = s[j] - 'a';
			v1 = T[v1].next[c];
			if (T[v1].fin != -1) {
				int v2 = 0;
				bool ok = true;
				int k = j + 1;
				for (; s[k]; k++) {
					char cc = s[k] - 'a';
					if (T[v2].next[cc] == -1) {
						ok = false;
						break;
					}
					v2 = T[v2].next[cc];
				}
				if (ok  && (T[v2].fin != -1))
          comp = true;
			}
		}
		if (comp) cout << s << '\n';
	}
}

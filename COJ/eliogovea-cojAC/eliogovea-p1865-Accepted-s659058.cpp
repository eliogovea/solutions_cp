#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

const int MAXN = 30000, alph = 26;

struct vertex {
	int fin;
	int fail;
	int link;
	int next[alph];
	vertex() {
		fin = fail = link = -1;
		for (int i = 0; i < alph; i++) next[i] = -1;
	}
} T[MAXN];

int n, m, states = 1;
string W[MAXN], P[MAXN];
map<string, int> sol;

void add(int pos) {
	const string &s = P[pos];
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		char c = s[i] - 'a';
		if (T[cur].next[c] == -1)
			T[cur].next[c] = states++;
		cur = T[cur].next[c];
	}
	T[cur].fin = pos;
}

queue<int> Q;

void build() {
	for (int i = 0; i < m; i++) add(i);
	for (int i = 0; i < alph; i++)
		if (T[0].next[i] == -1) {
			T[0].next[i] = 0;
		}
		else {
			T[T[0].next[i]].fail = 0;
			Q.push(T[0].next[i]);
		}
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < alph; i++)
			if (T[cur].next[i] != -1) {
				int next = T[cur].next[i];
				int fail = T[cur].fail;
				while (T[fail].next[i] == -1)
					fail = T[fail].fail;
				fail = T[fail].next[i];
				T[next].fail = fail;
				if (T[fail].fin != -1) T[next].link = fail;
				else T[next].link = T[fail].link;
				Q.push(next);
			}
	}
}

void match(int pos) {
	const string &s = W[pos];
	int cur = 0;
	for (int i = 0; s[i]; i++) {
		char c = s[i] - 'a';
		while (T[cur].next[c] == -1)
			cur = T[cur].fail;
    cur = T[cur].next[c];
		if (T[cur].fin != -1) sol[P[T[cur].fin]]++;
		for (int i = T[cur].link; i != -1; i = T[i].link)
			sol[P[T[i].fin]]++;
	}
}

int main() {
  //freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> W[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> P[i];
	build();
	for (int i = 0; i < n; i++) match(i);
	for (int i = 0; i < m; i++) cout << sol[P[i]] << "\n";
}

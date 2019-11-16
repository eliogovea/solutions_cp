#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXL = 90000;
const int MAXS = 2 * MAXL + 1;
 
int length[MAXS];
map <char, int> next[MAXS];
int suffixLink[MAXS];
int firstPos[MAXS];
bool terminal[MAXS];
 
int size;
int last;
 
inline int getNew(int _length) {
	length[size] = _length;
	next[size] = map <char, int> ();
	suffixLink[size] = -1;
	return size++;
}
 
inline int getClone(int from, int _length) {
	length[size] = _length;
	next[size] = next[from];
	suffixLink[size] = suffixLink[from];
	return size++;
}
 
inline void initSuffixAutomaton() {
	size = 0;
	last = getNew(0);
}
 
inline void extendSuffixAutomaton(char c) {
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
 
inline void makeTerminals() {
	int p = last;
	while (p != -1) {
		terminal[p] = true;
		p = suffixLink[p];
	}
}
 
int freq[MAXL];
int order[MAXS];
 
inline void getOrder(int maxLength = -1) {
	if (maxLength == -1) {
		for (int i = 0; i < size; i++) {
			maxLength = max(maxLength, length[i]);
		}
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
 
struct edge {
	int to;
	char c;
	int length;
};
 
bool operator < (const edge &a, const edge &b) {
	//assert(a.c != b.c);
	return a.c < b.c;
}
 
vector <edge> invSuffixLink[MAXS];
 
void buildSuffixTree(string &s) {
	initSuffixAutomaton();
	for (int i = ((int)s.size()) - 1; i >= 0; i--) {
		extendSuffixAutomaton(s[i]);
	}
	makeTerminals();
	getOrder(s.size());
	for (int i = size - 1; i >= 0; i--) {
		int x = order[i];
		if (terminal[x]) {
			firstPos[x] = 0;
		} else {
			firstPos[x] = s.size(); // INF
			for (map <char, int> :: iterator it = next[x].begin(); it != next[x].end(); it++) {
				firstPos[x] = min(firstPos[x], 1 + firstPos[it->second]);
			}
		}
	}
	for (int i = 1; i < size; i++) {
		edge e;
		e.to = i;
		e.c = s[firstPos[i] + length[suffixLink[i]]];
		e.length = length[i] - length[suffixLink[i]];
		invSuffixLink[suffixLink[i]].push_back(e);
	}
	for (int i = 0; i < size; i++) {
        if (invSuffixLink[i].size()) {
            sort(invSuffixLink[i].begin(), invSuffixLink[i].end());
        }
	}
}
 
struct query {
	long long k; // me pregunta por la k esima cadena
	int id; // posicion de la pregunta
};
 
bool operator < (const query &a, const query &b) {
	if (a.k != b.k) {
        return a.k < b.k;
	}
	return a.id < b.id;
}
 
const int MAXQ = 505;
 
string s;
int nQ;
query Q[MAXQ];
 
int ansLength[MAXQ];
int ansFirstPos[MAXQ];
 
void dfs(int now, long long &curID, int curLength, int &queryPos) {
	if (queryPos == nQ) {
		return;
	}
	for (int i = 0; i < invSuffixLink[now].size(); i++) {
		while (queryPos < nQ && curID + (long long)invSuffixLink[now][i].length >= Q[queryPos].k) {
			int l = Q[queryPos].k - curID;
			ansLength[Q[queryPos].id] = curLength + l;
			ansFirstPos[Q[queryPos].id] = firstPos[invSuffixLink[now][i].to];
			queryPos++;
		}
		curID += (long long)invSuffixLink[now][i].length;
		dfs(invSuffixLink[now][i].to, curID, curLength + invSuffixLink[now][i].length, queryPos);
	}
}
 
void solve() {
	cin >> s;
	buildSuffixTree(s);
	cin >> nQ;
	for (int i = 0; i < nQ; i++) {
		cin >> Q[i].k;
		Q[i].id = i;
	}
	sort(Q, Q + nQ);
	long long curID = 0;
	int queryPos = 0;
	dfs(0, curID, 0, queryPos);
	assert(queryPos == nQ);
	for (int i = 0; i < nQ; i++) {
		cout << s.substr(ansFirstPos[i], ansLength[i]) << "\n";
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

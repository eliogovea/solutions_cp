// Problem: pace=1&num=1713
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int S = 100;

const int SIZE = 2 * N * S + 100;
int n;
string word[N];
vector <int> wordId[SIZE];

int subTreeSize[SIZE];
int heavy[SIZE];

map <int, int> f;
int t = 0;

int answerLength[N + 10];
int answerPos[N + 10];

template <class T, int S>
struct suffixAutomaton {
	int length[S];
	map <T, int> go[S];
	int suffixLink[S];

    int firstWord[S];
	int firstPos[S];

	int root;
	int size;
	int last;

	int freq[S];
	int order[S];

	suffixAutomaton() {
		init();
	}

	void init() {
		size = 0;
		root = last = getNew(0, -1, -1);
	}

	int getNew(int _length, int _firstWord, int _firstPos) {
		length[size] = _length;
		go[size].clear();
		suffixLink[size] = -1;

        firstWord[size] = _firstWord;
		firstPos[size] = _firstPos;

		return size++;
	}

	int getClone(int from, int _length) {
		length[size] = _length;
		go[size] = go[from];
		suffixLink[size] = suffixLink[from];

        firstWord[size] = firstWord[from];
		firstPos[size] = firstPos[from];

		return size++;
	}

	void add(T c, int _firstWord, int _firstPos) {
		int p = last;
		if (go[p].find(c) != go[p].end()) {
			int q = go[p][c];
			if (length[p] + 1 == length[q]) {
				last = q;
			} else {
				last = getClone(q, length[p] + 1);
				suffixLink[q] = last;
				while (p != -1 && go[p][c] == q) {
					go[p][c]= last;
					p = suffixLink[p];
				}
			}
		} else {
			last = getNew(length[p] + 1, _firstWord, _firstPos);
			while (p != -1 && go[p].find(c) == go[p].end()) {
				go[p][c] = last;
				p = suffixLink[p];
			}
			if (p == -1) {
				suffixLink[last] = root;
			} else {
				int q = go[p][c];
				if (length[p] + 1 == length[q]) {
					suffixLink[last] = q;
				} else {
					int cq = getClone(q, length[p] + 1);
					suffixLink[q] = cq;
					suffixLink[last] = cq;
					while (p != -1 && go[p][c] == q) {
						go[p][c] = cq;
						p = suffixLink[p];
					}
				}
			}
		}
	}

	void _sort() {
		int mx = *max_element(length, length + size);
		for (int i = 0; i <= mx; i++) {
			freq[i] = 0;
		}
		for (int s = 0; s < size; s++) {
			freq[length[s]]++;
		}
		for (int i = 1; i <= mx; i++) {
			freq[i] += freq[i - 1];
		}
		for (int s = size - 1; s >= 0; s--) {
			order[--freq[length[s]]] = s;
		}
	}

    map <T, int> suffixTree[S];

    void buildSuffixTree() {
        _sort();
        for (int i = size - 1; i >= 0; i--) {
            int s = order[i];
            if (suffixLink[s] != -1) {
                T c = (T)word[firstWord[s]][firstPos[s] - length[suffixLink[s]]];
                suffixTree[suffixLink[s]][c]= s;
            }
        }
    }

};

suffixAutomaton <char, SIZE> sa;

int calcSubTreeSize(int u) {
    subTreeSize[u] = 1;
    heavy[u] = -1;
    for (auto to : sa.suffixTree[u]) {
        subTreeSize[u] += calcSubTreeSize(to.second);
        if (heavy[u] == -1 || subTreeSize[to.second] < subTreeSize[heavy[u]]) {
            heavy[u] = to.second;
        }
    }
    return subTreeSize[u];
}


void add(int root, int u, int delta) {
    for (auto x : wordId[u]) {
        f[x] += delta;
        if (f[x] == 0) {
            t--;
            f.erase(f.find(x));
        } else if (delta == 1 && f[x] == 1) {
            t++;
        }
    }
    for (auto to : sa.suffixTree[u]) {
        if (root == u && to.second == heavy[u] && delta == 1) {
            continue;
        }
        add(root, to.second, delta);
    }
}

void dfs(int u, bool keep) {
    for (auto to : sa.suffixTree[u]) {
        if (to.second != heavy[u]) {
            dfs(to.second, false);
        }
    }
    if (heavy[u] != -1) {
        dfs(heavy[u], true);
    }
    add(u, u, 1);

    if (t == 1) {
        int id = f.begin()->first;
        int l = sa.length[sa.suffixLink[u]] + 1;
        if (l < answerLength[id]) {
            answerLength[id] = l;
            answerPos[id] = sa.firstPos[u] - l + 1;
        }
    }
    
    if (!keep) {
        add(u, u, -1);
    }
}

void slow(int u, int p = -1) {
    for (auto to : sa.suffixTree[u]) {
        slow(to.second, u);
        for (auto x : wordId[to.second]) {
            wordId[u].push_back(x);
        }
    }
    sort(wordId[u].begin(), wordId[u].end());
    // wordId[u].erase(unique(wordId[u].begin(), wordId[u].end()), wordId[u].end());

    if (u == sa.root) {
        return;
    }

    cerr << "now: " << u << "\n";
    cerr << "parent: " << p << "\n";
    cerr << "substrings:\n";
    int id = sa.firstWord[u];
    int start = sa.firstPos[u] - sa.length[u] + 1;
    for (int l = sa.length[sa.suffixLink[u]] + 1; l <= sa.length[u]; l++) {
        cerr << word[id].substr(sa.firstPos[u] - l + 1, l) << "\n";
    }
    cerr << "belongs:\n";
    for (auto id : wordId[u]) {
        cerr << id << " ";
    }
    cerr << "\n-------------------------------------\n\n";

    if (wordId[u].size() == 1) {
        int id = wordId[u][0];
        int l = sa.length[sa.suffixLink[u]] + 1;
        if (l < answerLength[id]) {
            answerLength[id] = l;
            answerPos[id] = sa.firstPos[u] - l + 1;
        }
    }
/*
    add(u, u, 1);
    if (t == 1) {
        int id = f.begin()->first;
        int l = sa.length[sa.suffixLink[u]] + 1;
        cerr << id << " " << sa.firstPos[u] - l + 1 << " " << l << " " << sa.length[l] << "\n";
        if (l < answerLength[id]) {
            answerLength[id] = l;
            answerPos[id] = sa.firstPos[u] - l + 1;
        }
    }
    add(u, u, -1);
    for (auto to : sa.suffixTree[u]) {
        slow(to.second);
    }
*/
}

bool solve() {
    int  n;
    if (!(cin >> n)) {
        return false;
    }
    sa.init();
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        for (int j = 0; j < (int)word[i].size(); j++) {
            sa.add(word[i][j], i, j);
            wordId[sa.last].push_back(i);
        }
        sa.last = sa.root;

        answerLength[i] = word[i].size();
        answerPos[i] = 0;
    }
    sa.buildSuffixTree();

    // slow(sa.root);
    
    calcSubTreeSize(sa.root);
    dfs(sa.root, true);

    for (int i = 0; i < n; i++) {
        cout << word[i].substr(answerPos[i], answerLength[i]) << "\n";
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    solve();
}

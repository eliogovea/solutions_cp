// Problem: pace=1&num=1960
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

inline vector<int> manacher(string &s) {
    int n = s.size();
  vector<int> u(n <<= 1, 0);
  for (int i = 0, j = 0, k; i < n; i += k, j = std::max(j - k, 0)) {
    while (i >= j && i + j + 1 < n && s[(i - j) >> 1] == s[(i + j + 1) >> 1]) ++j;
    for (u[i] = j, k = 1; i >= k && u[i] >= k && u[i - k] != u[i] - k; ++k) {
      u[i + k] = std::min(u[i - k], u[i] - k);
    }
  }
  return u;
}

namespace SuffixAutomaton {
	const int MAXL = 2 * 100000 + 5;
	const int SIZE = 2 * MAXL + 1;

	int length[SIZE];
	map <char, int> next[SIZE];
	int suffixLink[SIZE];
	int firstPos[SIZE];
	int size;
	int last;

	inline int getNew(int _length, int _firstPos) {
		length[size] = _length;
		next[size] = map <char, int> ();
		suffixLink[size] = -1;
		firstPos[size] = _firstPos;
		return size++;
	}

	inline int getClone(int from, int _length) {
		length[size] = _length;
		next[size] = next[from];
		suffixLink[size] = suffixLink[from];
		firstPos[size] = firstPos[from];
		return size++;
	}

	inline void init() {
		size = 0;
		last = getNew(0, 0);
	}

	inline void add(char c, int pos) {
		int p = last;
		int cur = getNew(length[p] + 1, pos);
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

namespace FenwickTree {
	const int MAXL = 2 * 100000 + 5;
	const int SIZE = 2 * MAXL + 1;

	int size;
	int vals[SIZE];

	inline void init(int _size) {
		size = _size;
		for (int i = 0; i <= size; i++) {
			vals[i] = 0;
		}
	}

	inline void update(int pos, int val) {
		while (pos <= size) {
			vals[pos] += val;
			pos += pos & -pos;
		}
	}

	inline int get(int pos) {
		int res = 0;
		while (pos > 0) {
			res += vals[pos];
			pos -= pos & -pos;
		}
		return res;
	}

	inline int get(int l, int r) {
		return get(r) - get(l - 1);
	}
}

const int MAXL = 100000 + 5;

string s;

vector <int> removeEvents[2 * MAXL];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	SuffixAutomaton::init();
	FenwickTree::init(2 * s.size() - 1);

	int lastCenter = -1;
	long long currentAnswer = 0;

	vector <int> maxPal = manacher(s);
    /// !!! el centro de la cadena entre los indices [l, r] esta en l + r
	for (int i = 0; i < s.size(); i++) {
		SuffixAutomaton::add(s[i], i);
		while (lastCenter + 1 <= 2 * i) {
			/// remove events lastCenter
			if (lastCenter != -1) {
				for (int j = 0; j < removeEvents[lastCenter].size(); j++) {
					FenwickTree::update(removeEvents[lastCenter][j] + 1, -1);
				}
			}
			lastCenter++;
			if (lastCenter & 1) { // centro de un palindrome de largo par
				int length = (maxPal[lastCenter] + 1) / 2;
				//cerr << lastCenter << " "  << length << "\n";
				if (length != 0) { // centro de un palindrome de largo impar
					/// pongo cuando debo desactivar este estado porque de ahi en
					/// adelante no genera palindromes
					FenwickTree::update(lastCenter + 1, 1);
					removeEvents[2 * ((lastCenter / 2) + length)].push_back(lastCenter);
				}
			} else {
				int length = (maxPal[lastCenter] + 1) / 2;
				if (length != 0) {
					FenwickTree::update(lastCenter + 1, 1);
					removeEvents[2 * ((lastCenter / 2) + length - 1)].push_back(lastCenter);
				}
			}
		}
		/// el nuevo estado (last) acepta las cadenas desde largo i + 1 (la cadena completa hasta el caracter actual) hasta el largo que aceta su suffix link
		/// el primer centro sera el de la cadena completa que esta en i + 0
		/// el ultimo centro sera el de la minima cadena que acpta ese estado
		currentAnswer += FenwickTree::get(i + 0 + 1, i + (i - SuffixAutomaton::length[SuffixAutomaton::suffixLink[SuffixAutomaton::last]]) + 1);
		cout << currentAnswer;
		if (i + 1 < s.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}

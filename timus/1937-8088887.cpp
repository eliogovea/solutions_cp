// Problem: pace=1&num=1937
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

template <class T, int S>
struct suffixAutomaton {
	int length[S];
	map <T, int> go[S];
	int suffixLink[S];

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
		root = last = getNew(0, -1);
	}

	int getNew(int _length, int _firstPos) {
		length[size] = _length;
		go[size].clear();
		suffixLink[size] = -1;

		firstPos[size] = _firstPos;

		return size++;
	}

	int getClone(int from, int _length) {
		length[size] = _length;
		go[size] = go[from];
		suffixLink[size] = suffixLink[from];

		firstPos[size] = firstPos[from];

		return size++;
	}

	void add(T c, int _firstPos) {
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
			last = getNew(length[p] + 1, _firstPos);
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

};

const int SIZE = 4 * 100 * 1000 + 10;

suffixAutomaton <char, SIZE> sa;

template <class T>
vector <int> manacher(const T & s, int n) {
	vector <int> len(2 * n - 1);
	for (int i = 0, l = 0, r = -1; i < 2 * n - 1; i++) {
		int x = (i + 1) >> 1, y = i >> 1, z = 0;
		if (x < r) {
			z = min(len[2 * (l + r) - i], r - x);
		}
		while (0 <= x - z - 1 && y + z + 1 < n && s[x - z - 1] == s[y + z + 1]) {
			z++;
		}
		len[i] = z;
		if (y + z >= r) {
			l = x - z;
			r = y + z;
		}
	}
	return len;
}

bool isPalindrome(int l, int r, const vector <int> & len) {
	int x = (l + r + 1) >> 1, y = (l + r) >> 1, z = len[l + r];
	return x - z <= l && r <= y + z;
}
bool solve(string a, string b, int & pa, int & pb) {
	int na = a.size();
	a = a + a;
	// a = a.substr(0, a.size() - 1);

	auto ra = manacher(a, a.size());

	reverse(b.begin(), b.end());
	int nb = b.size();
	b = b + b;
	b = b.substr(0, b.size() - 1);

	sa.init();

	for (int i = 0; i < b.size(); i++) {
		sa.add(b[i], i);
	}

	int s = sa.root;
	int l = 0;

	for (int i = 0; i + (na - nb) < (int)a.size(); i++) {
		while (s != -1 && sa.go[s].find(a[i]) == sa.go[s].end()) {
			s = sa.suffixLink[s];
			if (s != -1) {
				l = sa.length[s];
			}
		}
		if (s == -1) {
			l = 0;
			s = sa.root;
		} else {
			l++;
			s = sa.go[s][a[i]];
		}

		if (l >= nb && isPalindrome(i + 1, i + (na - nb), ra)) {
			pa = i - nb + 1;
			pb = sa.firstPos[s];
			if (pb >= nb) {
				pb -= nb;
			}
			pb = nb - 1 - pb;
			if (pa + na - 1 < (int)a.size() && isPalindrome(pa + nb, pa + na - 1, ra)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int pa, pb;
	if (solve(a, b, pa, pb)) {
		assert(0 <= pa && pa < (int)a.size());
		cout << "Yes\n";
		cout << pa + 1 << " " << pb + 1 << "\n";
	} else {
		cout << "No\n";
	}
}

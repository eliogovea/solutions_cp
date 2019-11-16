// https://www.hackerrank.com/challenges/ashton-and-string

#include <bits/stdc++.h>

using namespace std;

const int L = 100 * 1000;

struct sa_node {
	int max_length;
	map <char, sa_node *> go;
	sa_node * suffix_link;
	vector <pair <char, sa_node *> > inv_suffix_link;
	int pos;
	bool visited;
};

const int SIZE = 2 * L + 10;

sa_node all[SIZE];
sa_node * _free;

sa_node * get_new(int max_length, int pos) {
	_free->max_length = max_length;
	_free->go.clear();
	_free->suffix_link = nullptr;
	_free->inv_suffix_link.clear();
	_free->pos = pos;
	_free->visited = false;
	return _free++;
}

sa_node * get_clone(sa_node * u, int max_length) {
	_free->max_length = max_length;
	_free->go = u->go;
	_free->suffix_link = u->suffix_link;
	_free->inv_suffix_link.clear();
	_free->pos = u->pos;
	_free->visited = false;
	return _free++;
}

sa_node * sa_reset() {
	_free = all;
	return get_new(0, -1);
}

sa_node * add(sa_node * root, sa_node * p, char c, int pos) {
	sa_node * l = get_new(p->max_length + 1, pos);
	while (p != nullptr && p->go.find(c) == p->go.end()) {
		p->go[c] = l;
		p = p->suffix_link;
	}
	if (p == nullptr) {
		l->suffix_link = root;
	} else {
		sa_node * q = p->go[c];
		if (p->max_length + 1 == q->max_length) {
			l->suffix_link = q;
		} else {
			sa_node * clone_q = get_clone(q, p->max_length + 1);
			l->suffix_link = clone_q;
			q->suffix_link = clone_q;
			while (p != nullptr && p != nullptr && p->go[c] == q) {
				p->go[c] = clone_q;
				p = p->suffix_link;
			}
		}
	}
	return l;
}

void dfs_sa(sa_node * now, const string & s) {
	now->visited = true;
	if (now->suffix_link != nullptr) {
		now->suffix_link->inv_suffix_link.push_back(make_pair(s[now->pos + now->suffix_link->max_length], now));
	}
	for (auto & to : now->go) {
		if (!to.second->visited) {
			dfs_sa(to.second, s);
		}
	}
}

inline long long calc(long long x) {
	return x * (x + 1) / 2LL;
}

char dfs_st(sa_node * root, sa_node * now, long long & k, const string & s) {
	if (now != root) {
		long long cnt = calc(now->max_length) - calc(now->suffix_link->max_length);
		if (cnt < k) {
			k -= cnt;
		} else {
			int lo = now->suffix_link->max_length;
			int hi = now->max_length;
			int p = lo;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				long long tmid = calc(mid) - calc(now->suffix_link->max_length);
				if (tmid < k) {
					p = mid;
					lo = mid + 1;
				} else {
					hi =  mid - 1;
				}
			}
			k -= calc(p) - calc(now->suffix_link->max_length);
			return s[now->pos + k - 1];
		}
	}
	sort(now->inv_suffix_link.begin(), now->inv_suffix_link.end());
	for (auto to : now->inv_suffix_link) {
		char res = dfs_st(root, to.second, k, s);
		if (res) {
			return res;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		string s;
		long long k;
		
		cin >> s >> k;
		
		sa_node * root = sa_reset();
		sa_node * last = root;
		
		for (int i = (int)s.size() - 1; i >= 0; i--) {
			last = add(root, last, s[i], i);
		}
		
		dfs_sa(root, s);
		cout << dfs_st(root, root, k, s) << "\n";
		
	}
}

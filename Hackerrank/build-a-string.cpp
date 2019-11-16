// https://www.hackerrank.com/challenges/build-a-string/problem
#include <bits/stdc++.h>

using namespace std;

const int L = 100 * 1000;

struct sa_node {
	int max_length;
	map <char, sa_node *> go;
	sa_node * suffix_link;
	vector <pair <char, sa_node *> > inv_suffix_link;
	int pos;
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
	return _free++;
}

sa_node * get_clone(sa_node * u, int max_length) {
	_free->max_length = max_length;
	_free->go = u->go;
	_free->suffix_link = u->suffix_link;
	_free->inv_suffix_link.clear();
	_free->pos = u->pos;
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

struct st_node {
	int value;
	int l, r;
	st_node * children[2];
	
	st_node() {
		value = 1e9;
		l = r = -1;
		children[0] = nullptr;
		children[1] = nullptr;
	};
};

st_node * build(int l, int r) {
	st_node * u = new st_node();
	u->value = 1e9;
	u->l = l;
	u->r = r;
	u->children[0] = nullptr;
	u->children[1] = nullptr;
	if (l != r) {
		int m = (l + r) >> 1;
		u->children[0] = build(l, m);
		u->children[1] = build(m + 1, r);
	}
	return u;
}

void update(st_node * root, int p, int v) {
	if (p < root->l || root->r < p) {
		return;
	}
	if (root->l == root->r) {
		root->value = v;
	} else {
		update(root->children[0], p, v);
		update(root->children[1], p, v);
		root->value = min(root->children[0]->value, root->children[1]->value);
	}
}

int query(st_node * root, int l, int r) {
	if (root->l > r || root->r < l) {
		return 1e9;
	}
	if (l <= root->l && root->r <= r) {
		return root->value;
	}
	return min(query(root->children[0], l, r), query(root->children[1], l, r));
}


// hackerrank problem
// https://www.hackerrank.com/challenges/build-a-string
void buildAString() {
	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		string s;

		cin >> n >> a >> b >> s;

		vector <int> dp(n + 1);

		sa_node * root = sa_reset();
		sa_node * last = root;
		
		st_node * st_root = build(0, n);
		update(st_root, 0, 0);

		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + a;
			last = add(root, last, s[i - 1], i);
			sa_node * now = last->suffix_link;
			while (now != root) {
				int l = i - now->max_length;
				int r = i - now->suffix_link->max_length - 1;
				if (l < now->pos) {
					l = now->pos;
				}
				if (l <= r) {
					dp[i] = min(dp[i], query(st_root, l, r) + b);
				}
				now = now->suffix_link;
			}
			update(st_root, i, dp[i]);
		}
		cout << dp[n] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	buildAString();
}

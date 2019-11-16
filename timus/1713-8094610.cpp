// Problem: pace=1&num=1713
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

struct sa_node {
	int max_length;
	map <char, sa_node *> go;
	sa_node * suffix_link;
	vector <pair <char, sa_node *>> inv_suffix_link;
	int id;
	int pos;
	bool ok;
	bool visited;
	
	sa_node() {}
};

const int SIZE = 2 * N + 10;

sa_node all[SIZE];
sa_node * first_free;

inline sa_node * get_new(int max_length, int id, int pos) {
	first_free->max_length = max_length;
	first_free->go = map <char, sa_node *> ();
	first_free->suffix_link = nullptr;
	first_free->inv_suffix_link = vector <pair<char, sa_node *> > ();
	first_free->id = id;
	first_free->pos = pos;
	first_free->ok = true;
	first_free->visited = false;
	return first_free++;
}

inline sa_node * sa_init() {
	first_free = all;
	return get_new(0, 0, 0);
}


inline sa_node * get_clone(sa_node * u, int max_length) {
	first_free->max_length = max_length;
	first_free->go = u->go;
	first_free->suffix_link = u->suffix_link;
	first_free->inv_suffix_link = vector <pair<char, sa_node *> > ();
	first_free->id = u->id;
	first_free->pos = u->pos;
	first_free->ok = u->ok;
	first_free->visited = false;
	return first_free++;
}

inline sa_node * add(sa_node * root, sa_node * p, char c, int id, int pos) {
	if (p->go.find(c) != p->go.end()) {
		sa_node * q = p->go[c];
		if (p->max_length + 1 == q->max_length) {
			return q;
		}
		sa_node * clone_q = get_clone(q, p->max_length + 1);
		q->suffix_link = clone_q;
		while (p != nullptr && p->go[c] == q) {
			p->go[c] = clone_q;
			p = p->suffix_link;
		}
		return clone_q;
	}
	sa_node * l = get_new(p->max_length + 1, id, pos);
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
			while (p != nullptr && p->go[c] == q) {
				p->go[c] = clone_q;
				p = p->suffix_link;
			}
		}
	}
	return l;
}

string s[N];
int answer_pos[N];
int answer_length[N];

pair <sa_node *, int> st[SIZE];
int st_top;

inline void solve() {
	int n;
	cin >> n;
	
	sa_node * root = sa_init();
	root->ok = false;
	sa_node * last = root;
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		for (int p = 0; p < (int)s[i].size(); p++) {
			last = add(root, last, s[i][p], i, p);
			if (last->id != i) {
				last->ok = false;
			}
		}
		last = root;
		answer_pos[i] = -1;
	}
	
	for (sa_node * now = all; now != first_free; now++) {
		if (now->suffix_link != nullptr) {
			now->suffix_link->inv_suffix_link.push_back(make_pair(s[now->id][now->pos - now->suffix_link->max_length], now));
		}
	}
	
	for (sa_node * now = all; now != first_free; now++) {
		sort(now->inv_suffix_link.begin(), now->inv_suffix_link.end());
	}
	
	st[st_top++] = make_pair(root, 0);
	
	while (st_top > 0) {
		sa_node * now = st[st_top - 1].first;
		int & ind = st[st_top - 1].second;
		if (ind == (int)now->inv_suffix_link.size()) {
			if (now->ok) {
				if (answer_pos[now->id] == -1 || answer_length[now->id] > now->suffix_link->max_length + 1) {
					answer_pos[now->id] = now->pos - now->suffix_link->max_length;
					answer_length[now->id] = now->suffix_link->max_length + 1;
				}
			}
			if (now->suffix_link != nullptr) {
				if (!now->ok || now->id != now->suffix_link->id) {
					now->suffix_link->ok = false;
				}
			}
			st_top--;
		} else {
			st[st_top++] = make_pair(now->inv_suffix_link[ind].second, 0);
			ind++;
		}
	}
	
	string answer;
	
	for (int i = 0; i < n; i++) {
		if (answer_pos[i] == -1) {
			cout << "IMPOSSIBLE\n";
		} else {
			answer = s[i].substr(answer_pos[i], answer_length[i]);
			reverse(answer.begin(), answer.end()); 
			cout << answer << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	
}
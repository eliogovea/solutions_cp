#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct treap_node {
	int value;
	int sub_tree_size;
	int min_value;
	int priority;
	int lazy_reverse;	
	treap_node * left;
	treap_node * right;
	
	treap_node(int _value) {
		value = _value;
		sub_tree_size = 1;
		min_value = value;
		priority = (rand() << 15) | rand();
		lazy_reverse = 0;
		left = nullptr;
		right = nullptr;
	}
};

inline int get_sub_tree_size(treap_node * now) {
	return now != nullptr ? now->sub_tree_size : 0;
}

inline int get_min_value(treap_node * now) {
	return now != nullptr ? now->min_value : INF;
}

inline void update_treap_node(treap_node * now) {
	if (now != nullptr) {
		now->sub_tree_size = 1 + get_sub_tree_size(now->left) + get_sub_tree_size(now->right);
		now->min_value = min(now->value, min(get_min_value(now->left), get_min_value(now->right)));
	}
}

inline void push_lazy(treap_node * now) {
	if (now != nullptr && now->lazy_reverse) {
		if (now->left != nullptr) {
			now->left->lazy_reverse ^= 1;
		}
		if (now->right != nullptr) {
			now->right->lazy_reverse ^= 1;
		}
		swap(now->left, now->right);		
		now->lazy_reverse = 0;
	}
}

treap_node * merge(treap_node * left, treap_node * right) {
	push_lazy(left);
	push_lazy(right);
	if (left == nullptr) {
		return right;
	}
	if (right == nullptr) {
		return left;
	}
	if (left->priority > right->priority) {
		left->right = merge(left->right, right);
		update_treap_node(left);
		return left;
	}
	right->left = merge(left, right->left);
	update_treap_node(right);
	return right;
}

pair <treap_node *, treap_node *> split(treap_node * now, int where) {
	if (where == 0) {
		return make_pair(nullptr, now);
	}
	if (now == nullptr) {
		return make_pair(nullptr, nullptr);
	}
	push_lazy(now);
	int left_size = get_sub_tree_size(now->left);
	if (left_size >= where) {
		pair <treap_node *, treap_node *> left_split = split(now->left, where);
		now->left = left_split.second;
		update_treap_node(now);
		return make_pair(left_split.first, now);
	}
	pair <treap_node *, treap_node *> right_split = split(now->right, where - (left_size + 1));
	now->right = right_split.first;
	update_treap_node(now);
	return make_pair(now, right_split.second);
}

int get_position(treap_node * now, int value) {
	// assert(now != nullptr);
	// assert(now->min_value == value);
	push_lazy(now);
	if (now->value == value) {
		return 1 + get_sub_tree_size(now->left);
	}
	if (get_min_value(now->left) == value) {
		return get_position(now->left, value);
	}
	return get_sub_tree_size(now->left) + 1 + get_position(now->right, value);
}

void print_treap(treap_node * now) {
	if (now == nullptr) {
		return;
	}
	print_treap(now->left);
	cout << "(" << now->value << ", " << now->min_value << ") ";
	print_treap(now->right);
}

void robotic_sort() {
	int n;
	while (cin >> n && n != 0) {
		treap_node * root = nullptr;
		
		vector <int> p(n);
		vector <pair <int, int> > q(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			q[i] = make_pair(p[i], i);
		}
		
		sort(q.begin(), q.end());
		
		for (int i = 0; i < n; i++) { // i != j => p[i] != p[j]
			p[i] = lower_bound(q.begin(), q.end(), make_pair(p[i], i)) - q.begin();
		}
		
		for (int i = 0; i < n; i++) {
			root = merge(root, new treap_node(p[i]));
		}
		
		// print_treap(root); cerr << "\n";
		
		
		for (int i = 0; i < n; i++) {
			int pos = get_position(root, i);
			
			cout << i + pos;
			if (i + 1 < n) {
				cout << " ";
			}
			
			pair <treap_node *, treap_node *> first_split = split(root, pos);
			pair <treap_node *, treap_node *> second_split = split(first_split.first, pos - 1);
			
			if (second_split.first != nullptr) {
				second_split.first->lazy_reverse ^= 1;
			}
			
			delete second_split.second;
			
			root = merge(second_split.first, first_split.second);
		}
		cout << "\n";
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	robotic_sort();
}
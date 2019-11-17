#include <bits/stdc++.h>

using namespace std;

struct node {
	int next[2];
	node() {
		next[0] = next[1] = -1;
	}
} t[30 * 4 * 100005];

int sz;

void init() {
	for (int i = 0; i < sz; i++) {
		t[i] = node();
	}
	sz = 1;
}

void add(int x) {
	int cur = 0;
	for (int i = 30; i >= 0; i--) {
		int y = ((x & (1 << i)) != 0) ? 1 : 0;
		if (t[cur].next[y] == -1) {
			t[cur].next[y] = sz++;
		}
		cur = t[cur].next[y];
	}
}

int get_max(int x) {
	int res = 0;
	int cur = 0;
	for (int i = 30; i >= 0; i--) {
		int y = ((x & (1 << i)) != 0) ? 1 : 0;
		y ^= 1;
		if (t[cur].next[y] != -1) {
			res |= (1 << i);
			cur = t[cur].next[y];
		} else {
			cur = t[cur].next[y ^ 1];
		}
	}
	return res;
}

int n;
int arr[4 * 100005];
int bst[4 * 100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	init();
	int xor_sum = 0;
	add(xor_sum);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		xor_sum ^= arr[i];
		bst[i] = max(bst[i - 1], get_max(xor_sum));
		add(xor_sum);
	}

	init();
	add(0);
	xor_sum = 0;
	int mx = 0;
	int ans = 0;
	for (int i = n; i > 1; i--) {
		xor_sum ^= arr[i];
		int tmp = get_max(xor_sum);
		add(xor_sum);
		if (tmp > mx) {
			mx = tmp;
		}
		tmp = mx + bst[i - 1];
		if (tmp > ans) {
			ans = tmp;
		}
	}
	cout << ans << "\n";
}


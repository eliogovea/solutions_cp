#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int lis(vector<int> &v) {
	int n = v.size();
	vector<int> A(n, 1 << 29), id(n);
	for (int i = 0; i < n; i++) {
		id[i] = lower_bound(A.begin(), A.end(), v[i]) - A.begin();
		A[id[i]] =	v[i];
	}
	return *max_element(id.begin(), id.end()) + 1;
}

int n, l1, l2;
vector<int> v;

int main() {
  //freopen("e.in", "r", stdin);
	while (cin >> n) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		l1 = lis(v);
		reverse(v.begin(), v.end());
		l2 = lis(v);
		if (l1 == l2)
			cout << "Caution. I will not intervene.\n";
    else cout << "Don't worry. I must intervene.\n";
	}
}

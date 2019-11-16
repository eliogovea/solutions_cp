#include <bits/stdc++.h>
using namespace std;

int td, n, sol;
vector<pair<int, int> > v;

int main() {
	scanf("%d", &td);
	while (td--) {
		scanf("%d", &n);
		v.clear();
		sol = 0;
		for (int i = 0, a, b; i < n; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		if (n == 0) printf("0\n");
		else if (n == 1) printf("%d\n", v[0].second - v[0].first + 1);
		else {
			int a = v[0].first, b = v[0].second;
			for (int i = 1; i < n; i++) {
				if (v[i].first <= b) b = max(b, v[i].second);
				else {
					sol += b - a + 1;
					a = v[i].first;
					b = v[i].second;
				}
			}
			sol += b - a + 1;
			printf("%d\n", sol);
		}
	}
}

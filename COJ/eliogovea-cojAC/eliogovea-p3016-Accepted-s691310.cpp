//============================================================================
// Name        : 3016.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 40005;

int n, x, y, z, a[N + 5], b[N + 5], ac[N + 5], ans;
vector<int> v;

int main() {
	scanf("%d%d%d%d", &n, &x, &y, &z);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) {
		a[i] = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
		b[i] = upper_bound(v.begin(), v.end(), b[i]) - v.begin();
		ac[0] += x;
		ac[a[i]] -= x;
		ac[a[i]] += y;
		ac[b[i] + 1] -= y;
		ac[b[i] + 1] += z;
		ac[N] -= z;
	}
	int sz = v.size() + 1;
	for (int i = 1; i <= sz; i++) {
		ac[i] += ac[i - 1];
		if (ac[i] > ans) {
			ans = ac[i];
		}
	}
	printf("%d\n", ans);
}

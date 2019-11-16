#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

int c, n, arr[MAXN], sol;

int main() {
	for (scanf("%d", &c); c--;) {
		scanf("%d", &n);
		sol = 0;
		for (int i = 1; i <= n; i++) scanf("%d", arr + i);
		sort(arr + 1, arr + 1 + n, greater<int>());
		for (int i = 1; i <= n; i++)
			if (arr[i] >= i) sol = max(sol, i);
		printf("%d\n", sol);
	}
}

//============================================================================
// Name        : 1929.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a, c, m, f0, q, n, x, f[100000005];
char s[10];

int main() {
	scanf("%d%d%d%d%d%d", &a, &c, &m, &f0, &q, &n);
	f[1] = f0;
	for (int i = 2; i <= n; i++)
		f[i] = (a * f[i - 1] + c) % m;
	scanf("%s", s);
	if (s[0] == 'A') sort(f + 1, f + 1 + n);
	else sort(f + 1, f + 1 + n, greater<int>());

	while (q--) {
		scanf("%d", &x);
		printf("%d\n", f[x]);
	}
}

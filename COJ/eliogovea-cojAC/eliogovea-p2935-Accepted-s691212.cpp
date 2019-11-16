//============================================================================
// Name        : 2935.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cmath>

const int N = 1000001;

int f[15];
double cd[12][N + 5];

int solve(int n, int b) {
	if (n < 10) {
		n = f[n + 1] - 1;
		int ans = log(n) / log(b);
		ans++;
		return ans;
	}
	int ans = cd[b][n + 1];
	ans++;
	return ans;
}

int tc, n, b;

int main() {
	f[0] = 1;
	for (int i = 1; i <= 10; i++) f[i] = f[i - 1] * i;
	for (int i = 2; i <= 10; i++)
		for (int j = 2; j <= N; j++)
			cd[i][j] = cd[i][j - 1] + log(j) / log(i);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &b);
		printf("%d\n", solve(n, b));
	}
}

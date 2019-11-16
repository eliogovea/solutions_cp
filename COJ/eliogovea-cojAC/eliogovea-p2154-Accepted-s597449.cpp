#include <cstdio>

const int MAXN = 1010;

int c, n, mark['z' + 1], id;
char mat[MAXN][MAXN];

bool f() {
	for (int i = 0; i < n / 2; i++) {
		if (mark[mat[i][i]] == id) return 0;
		mark[mat[i][i]] = id;
		for (int j = i; j < n - i; j++)
			if (mat[i][j] != mat[i][i] ||
				mat[j][i] != mat[i][i] ||
				mat[n - i - 1][j] != mat[i][i] ||
				mat[j][n - i - 1] != mat[i][i]) return 0;
	}
	if (n & 1 && mark[mat[n / 2][n / 2]] == id) return  0;
	return 1;
}

int main() {
	for (scanf("%d", &c); c--;) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%s", mat[i]);
		id++;
		printf("%s\n", f() ? "YES" : "NO");
	}
}

#include <cstdio>

const int MAXN = 110;

char line[MAXN];
int n, matH[MAXN][MAXN], matC[MAXN][MAXN];

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void busH(int i, int j, int tip) {
	if (matH[i][j] != tip) return;
	matH[i][j] = 0;
	for (int r = 0; r < 4; r++)
		busH(i + dx[r], j + dy[r], tip);
}

void busC(int i, int j, int tip) {
	if (matC[i][j] != tip) return;
	matC[i][j] = 0;
	for (int r = 0; r < 4; r++)
		busC(i + dx[r], j + dy[r], tip);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", line + 1);
		for (int j = 1; j <= n; j++) {
			if (line[j] == 'B') matH[i][j] = matC[i][j] = 1;
			else if (line[j] == 'R') matH[i][j] = matC[i][j] = 2;
			else matH[i][j] = 3, matC[i][j] = 2;
		}
	}
	int cH = 0, cC = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (matH[i][j]) {cH++; busH(i, j, matH[i][j]);}
			if (matC[i][j]) {cC++; busC(i, j, matC[i][j]);}
		}
	printf("%d %d", cH, cC);
}

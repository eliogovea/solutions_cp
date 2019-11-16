#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, k, mat[MAXN + 10][MAXN + 10], sol;

int f(int i, int j)
{
	if (i < 1 || j < 1 || i > n || j > m) return 0;
	if (!mat[i][j]) return 0;
	mat[i][j] = 0;
	int r = 1;
	for (int k = 0; k < 4; k++)
		r += f(i + mov[k][0], j + mov[k][1]);
	return r;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, a, b; i < k; i++)
	{
		scanf("%d%d", &a, &b);
		mat[a][b] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j]) sol = max(sol, f(i, j));
	printf("%d\n", sol);
}

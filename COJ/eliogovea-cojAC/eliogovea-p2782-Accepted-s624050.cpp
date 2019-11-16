#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 15, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

char mat[MAXN][MAXN];
int n, im, jm, ifin, jfin;
queue<int> Qi, Qj;
int dist[MAXN][MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", mat[i]);
		for (int j = 0; j < n; j++)
			if (mat[i][j] == 'm') im = i, jm = j;
			else if (mat[i][j] == '#') ifin = i, jfin = j;
	}
	dist[im][jm] = 1;
	Qi.push(im); Qj.push(jm);
	while (!Qi.empty()) {
		int ii = Qi.front(), jj = Qj.front();
        //printf("%d %d\n", ii, jj);
		Qi.pop(); Qj.pop();
		for (int r = 0; r < 4; r++) {
			int ni = ii + dx[r], nj = jj + dy[r];
			//printf("%d %d\n", ni, nj);
			if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
			if (dist[ni][nj] || mat[ni][nj] == '*') continue;
			dist[ni][nj] = dist[ii][jj] + 1;
			Qi.push(ni);
			Qj.push(nj);
		}
	}
	if (dist[ifin][jfin]) printf("%d\n", dist[ifin][jfin] - 1);
	else printf("-1\n");
}

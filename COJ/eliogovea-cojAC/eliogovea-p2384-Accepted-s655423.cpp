#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 55, inf = 1 << 29;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int tc, n, m, I, J;
char M[MAXN][MAXN];
int dist[MAXN][MAXN];
queue<int> Q;

int nexti[4][MAXN][MAXN], nextj[4][MAXN][MAXN];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", M[i]);
			for (int j = 0; j < m; j++)
				if (M[i][j] == 'F') dist[i][j] = 0, I = i, J = j;
				else dist[i][j] = inf;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] == 'F' || M[i][j] == '.')
					for (int d = 0; d < 4; d++) {
						int ii = i + dx[d], jj = j + dy[d];
						while (ii >= 0 && ii < n && jj >= 0 && jj < m && M[ii][jj] != '.' && M[ii][jj] != 'F')
							ii += dx[d], jj += dy[d];
						if (ii >= 0 && ii < n && jj >= 0 && jj < m)
							nexti[d][i][j] = ii, nextj[d][i][j] = jj;
						else nexti[d][i][j] = -1, nextj[d][i][j] = -1;
					}

		Q.push(I); Q.push(J);
		while (!Q.empty()) {
			I = Q.front(); Q.pop();
			J = Q.front(); Q.pop();
			for (int d = 0; d < 4; d++) {
				if (nexti[d][I][J] != -1) {
					int ii = nexti[d][I][J];
					int jj = nextj[d][I][J];
					if (dist[ii][jj] > dist[I][J] + 1) {
						dist[ii][jj] = dist[I][J] + 1;
						Q.push(ii), Q.push(jj);
					}
				}
			}
		}
		int mx = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (dist[i][j] != inf && dist[i][j] > mx) mx = dist[i][j];
		printf("%d\n", mx);
	}
}

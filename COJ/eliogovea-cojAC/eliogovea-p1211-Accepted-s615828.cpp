#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

typedef long long ll;

ll n, x[MAXN], y[MAXN], d, dist[MAXN][MAXN], ind[MAXN], sol;

int main() {
	while (scanf("%lld", &n) && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld", x + i, y + i);
			for (int j = 1; j < i; j++) {
				d = (x[i] - x[j]) * (x[i] - x[j])
						+ (y[i] - y[j]) * (y[i] - y[j]);
				dist[i][ind[i]++] = d;
				dist[j][ind[j]++] = d;
			}
		}
		for (int i = 1; i <= n; i++) {
			sort(dist[i], dist[i] + ind[i]);
			for (int j = 0, act = 0; ; j++)
				if (j == ind[i] || dist[i][j] != dist[i][act]) {
					sol += (j - act - 1) * (j - act) / 2;
					act = j;
					if (j == ind[i]) break;
				}
		}
		printf("%lld\n", sol);
		sol = 0;
		for (int i = 0; i <= n; i++) ind[i] = 0;
	}
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 55, inf = 1ll << 60;

ll x, y, z, arr[MAXN][MAXN][MAXN], aux[MAXN];

ll max_sum() {
	ll r = -inf;
	for (int x1 = 1; x1 <= x; x1++)
		for (int x2 = 1; x2 <= x1; x2++)
			for (int y1 = 1; y1 <= y; y1++)
				for (int y2 = 1; y2 <= y1; y2++) {
					for (int z1 = 1; z1 <= z; z1++)
						aux[z1] = arr[x1][y1][z1] - arr[x1][y2 - 1][z1]
											 - arr[x2 - 1][y1][z1] + arr[x2 - 1][y2 - 1][z1];
					for (int z1 = 1; z1 <= z; z1++) {
						aux[z1] = max(aux[z1], aux[z1] + aux[z1 - 1]);
						r = max(r, aux[z1]);
					}
				}
	return r;
}

int main() {
	cin >> x >> y >> z;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			for (int k = 1; k <= z; k++)
				cin >> arr[i][j][k];
	for (int zz = 1; zz <= z; zz++)
		for (int xx = 1; xx <= x; xx++)
			for (int yy = 1; yy <= y; yy++)
				arr[xx][yy][zz] += arr[xx - 1][yy][zz] + arr[xx][yy - 1][zz]
														 - arr[xx - 1][yy - 1][zz];
	cout << max_sum() << "\n";
}

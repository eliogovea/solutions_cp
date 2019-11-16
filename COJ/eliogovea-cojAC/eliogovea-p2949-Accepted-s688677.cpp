#include <cstdio>
#include <cmath>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int n, a[1000][1000];

int main() {
	scanf("%d", &n);
	for (int i = 0, x, y, r; i < n; i++) {
		scanf("%d%d%d", &x, &y, &r);
		x += 100; y += 100;
		if (a[x][y] <= r) a[x][y] = r;
	}
	for (int i = 0; i <= 200; i++)
		for (int j = 0; j <= 200; j++)
			for (int k = i - a[i][j]; k <= i + a[i][j]; k++)
				for (int l = j - a[i][j]; l <= j + a[i][j]; l++)
					if (k >= 0 && k <= 200 && l >= 0 && l <= 200 && (i != k || j != l) && (double(a[i][j]) >= dist(i, j, k, l) + double(a[k][l])))
						a[k][l] = 0;
	n = 0;
	for (int i = 0; i <= 200; i++)
		for (int j = 0; j <= 200; j++)
			if (a[i][j]) n++;
	printf("%d\n", n);
}

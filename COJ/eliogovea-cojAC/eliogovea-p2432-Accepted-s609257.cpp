#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n, arr[MAXN];

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) scanf("%d", arr + i);
		sort(arr + 1, arr + n + 1);
		if (n & 1) printf("%.1lf\n", (double)arr[(n + 1) / 2]);
		else {
			double sol = ((double)arr[n / 2] + (double)arr[n / 2 + 1]) / 2.0;
			printf("%.1lf\n", sol);
		}
	}
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXM = 1010;

int n, m, arr[MAXM], pre, gan;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d", &arr[i]);
	sort(arr, arr + m);
	for (int i = 0; i < m; i++)
		if (gan < arr[i] * min(m - i, n)) {
			pre = arr[i];
			gan = arr[i] * min(m - i, n);
		}
	printf("%d %d", pre, gan);
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1100;

int n, arr[MAXN], sol[MAXN], ind = 1;

void f(int idx) {
	if (idx > n) return;
	sol[idx] = arr[ind++];
	f(2 * idx);
	f(2 * idx + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", arr + i);
	sort(arr + 1, arr + n + 1);
	f(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", sol[i]);
		if (i != n) printf(" ");
		else printf("\n");
	}
}

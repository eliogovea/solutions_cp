#include <cstdio>

int tc, x, arr[1010];

void f(int n, int ind, int last) {
	if (n == 0) {
	    printf("%d = ", x);
        for (int i = 0; i < ind; i++) printf("%d%s", arr[i], (i != ind - 1) ? " + " : "\n");
    }
	for (int i = last; i <= n; i++) {
	    arr[ind] = i;
		f(n - i, ind + 1, i);
	}
}

int main() {
	for (scanf("%d", &tc); tc--;) {
		scanf("%d", &x);
		f(x, 0, 1);
		if (tc) printf("\n");
	}
}

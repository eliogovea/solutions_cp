#include <cstdio>
#include <map>

using namespace std;

int n, sol, x[1005], y[1005];

map<pair<int, int>, int> M;
map<pair<int, int>, int>::iterator it;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		for (int j = 0; j < i; j++)
			sol += M[make_pair(x[i] + x[j], y[i] + y[j])]++;
	}
	printf("%d\n", sol);
}


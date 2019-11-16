#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

char name[MAXN];
int a, b;

int main() {
	scanf("%s%d%d", name, &a, &b);
	printf("%s %d\n", name, abs(a - b));
}

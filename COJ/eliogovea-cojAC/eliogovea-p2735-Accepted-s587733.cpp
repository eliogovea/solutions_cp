#include <cstdio>
#include <algorithm>
using namespace std;

struct eq
{
	int o, p, b, id;
	bool operator < (const eq &x) const
	{
		if (o != x.o) return o > x.o;
		if (p != x.p) return p > x.p;
		if (b != x.b) return b > x.b;
		return id < x.id;
	}
}arr[7];

int main()
{
	for (int i = 0, a, b, c; i < 7; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = (eq) {a, b, c, i + 1};
	}
	sort(arr, arr + 7);

	for (int i = 0; i < 7; i++)
		printf("Facultad %d %d %d %d\n", arr[i].id, arr[i].o, arr[i].p, arr[i].b);
}

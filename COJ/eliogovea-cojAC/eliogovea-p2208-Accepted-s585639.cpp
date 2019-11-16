///COJ - 2208 - Another Problem From My Teacher
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, x;

int main()
{
	scanf("%d", &n);
	vector<pair<int, int> > v(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v[i] = make_pair(x, i);
	}
	sort(v.begin(), v.end());
	int pos = 0, sol = -1;
	for (int i = 1; i < n; i++)
		if (v[i].second > v[pos].second)
			sol = max(sol, v[i].second - v[pos].second + 1);
		else pos = i;
	printf("%d\n", sol);
}

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;

double dist(int a, int b, int c, int d)
{
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main()
{
	scanf("%d", &n);
	vector<pair<int, pair<int, int> > > v(n);
	for (int i = 0, a, b, c; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		v[i] = make_pair(a, make_pair(b, c));
	}

	int in, fn;
	scanf("%d%d", &in, &fn);

	for (int i = 0; i < n; i++)
	{
		if (v[i].first == in) swap(v[0], v[i]);
		if (v[i].first == fn) swap(v[n - 1], v[i]);
	}

	sort(++v.begin(), --v.end());
	double sol = 1e10;
	do
	{
		double aux = 0.0;
		for (int i = 1; i < n; i++)
			aux += dist(v[i].second.first, v[i].second.second, v[i - 1].second.first, v[i - 1].second.second);
		sol = min(sol, aux);
	} while (next_permutation(++v.begin(), --v.end()));
	printf("%.2lf\n", sol);
}

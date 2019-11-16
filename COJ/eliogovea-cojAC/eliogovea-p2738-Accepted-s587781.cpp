#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 510;

struct pt
{
	int x, y;
}pts[MAXN];

struct edge
{
	int i, f;
	double	c;
	bool operator < (const edge &o) const
	{
		return c < o.c;
	}
};

vector<edge> edges;

int n, m, p[MAXN], rank[MAXN];

void make(int x)
{
	p[x] = x;
	rank[x] = 0;
}

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

bool join(int x, int y)
{
	int px = find(x), py = find(y);
	if (px == py) return false;
	if (rank[px] > rank[py]) p[py] = px;
	else if (rank[py] > rank[px]) p[px] = py;
	else p[px] = py, rank[py]++;
	return true;
}

double dist(int i, int j)
{
	return sqrt((pts[i].x - pts[j].x) * (pts[i].x - pts[j].x)
				+ (pts[i].y - pts[j].y) * (pts[i].y - pts[j].y));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0, a, b, c; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		pts[a] = (pt) {b, c};
		make(a);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			edges.push_back((edge) {i, j, dist(i, j)});
	scanf("%d", &m);
	double sol = 0.0;
	for (int i = 0, a, b; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		join(a, b);
		sol += dist(a, b);
	}
	sort(edges.begin(), edges.end());
	for (vector<edge>::iterator it = edges.begin(); it != edges.end(); it++)
		if (join(it->i, it->f)) sol += it->c;
	printf("%.2lf\n", sol);
}
